class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> mp;
        for(auto i: moves) mp[i]++;
        return max(mp['L'], mp['R']) - min(mp['L'], mp['R']) + mp['_'];
    }
};