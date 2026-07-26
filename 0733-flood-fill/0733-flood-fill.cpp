class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //algo(bfs)
        //start from the given coordinates
        //put it in the queue
        //check it's neighbours, if same color, update, put in the queue
    
        queue<pair<int,int>>q;
        int org = image[sr][sc];
        image[sr][sc] = color;
        if(org == color) return image;
        q.push({sr, sc});

        //assistance for neighbours
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};
        while(!q.empty()){
            pair<int,int> pixel = q.front();
            int pr = pixel.first;
            int pc = pixel.second;
            q.pop();
            //check all neighbours
            for(int i = 0; i<4; i++){
                int r = pr + row[i];
                int c = pc + col[i];
if(r >= 0 && r < image.size() &&
   c >= 0 && c < image[0].size()){
                if(image[r][c] == org){
                    image[r][c] = color;
                    q.push({r,c});
                }}
            }
        }
        return image;
    }
};