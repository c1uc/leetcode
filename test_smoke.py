"""Smoke tests to verify refactored modules are importable and safe."""

import inspect


def test_sync_daily_importable():
    from sync_daily import run
    assert callable(run)


def test_sync_submissions_importable():
    from sync_submissions import run, SessionExpiredError
    assert callable(run)
    assert issubclass(SessionExpiredError, Exception)


def test_no_sys_exit_in_run():
    """Verify sys.exit() is not called (outside docstrings/comments) in run() functions."""
    import ast
    import sync_daily
    import sync_submissions

    for mod in [sync_daily, sync_submissions]:
        source = inspect.getsource(mod.run)
        tree = ast.parse(source)
        for node in ast.walk(tree):
            if (
                isinstance(node, ast.Call)
                and isinstance(node.func, ast.Attribute)
                and isinstance(node.func.value, ast.Name)
                and node.func.value.id == "sys"
                and node.func.attr == "exit"
            ):
                raise AssertionError(f"sys.exit() call found in {mod.__name__}.run()")
