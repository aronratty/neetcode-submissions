
class Solution {
private:
    bool dfs(int course,
             unordered_map<int, vector<int>>& adjList,
             vector<int>& state) {

        if (state[course] == 1) return false;
        if (state[course] == 2) return true;

        state[course] = 1;

        for (int nextCourse : adjList[course]) {
            if (!dfs(nextCourse, adjList, state)) {
                return false;
            }
        }

        state[course] = 2;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prereqs) {
        unordered_map<int, vector<int>> mp;

        for (auto& course : prereqs) {
            mp[course[0]].push_back(course[1]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, mp, state)) {
                return false;
            }
        }

        return true;
    }
};
