#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

class TaskManager {
    public:
    using tii = tuple<int, int, int>;
    priority_queue<tii, vector<tii>, less<tii>> pq;
    vector<int> priorities;
    vector<int> taskToUser;
    
        TaskManager(vector<vector<int>>& tasks) {
            priorities = vector<int>(MAX_N, -1);
            taskToUser = vector<int>(MAX_N, -1);
            for(auto& task : tasks) {
                pq.push({task[2], task[1], task[0]});
                priorities[task[1]] = task[2];
                taskToUser[task[1]] = task[0];
            }
        }
        
        void add(int userId, int taskId, int priority) {
            pq.push({priority, taskId, userId});
            priorities[taskId] = priority;
            taskToUser[taskId] = userId;
        }
        
        void edit(int taskId, int newPriority) {
            priorities[taskId] = newPriority;
            pq.push({newPriority, taskId, taskToUser[taskId]});
        }
        
        void rmv(int taskId) {
            priorities[taskId] = -1;
            taskToUser[taskId] = -1;
        }
        
        int execTop() {
            while(!pq.empty()) {
                auto [priority, taskId, userId] = pq.top();
                pq.pop();
                if(priorities[taskId] == priority && taskToUser[taskId] == userId) {
                    priorities[taskId] = -1;
                    taskToUser[taskId] = -1;
                    return userId;
                }
            }
            return -1;
        }
    };
    
    /**
     * Your TaskManager object will be instantiated and called as such:
     * TaskManager* obj = new TaskManager(tasks);
     * obj->add(userId,taskId,priority);
     * obj->edit(taskId,newPriority);
     * obj->rmv(taskId);
     * int param_4 = obj->execTop();
     */
