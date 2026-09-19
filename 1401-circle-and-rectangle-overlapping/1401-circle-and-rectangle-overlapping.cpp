class Solution {
public:
    bool checkOverlap(int radius, int cx, int cy, int x1, int y1, int x2, int y2) {
        if(cx>=x1 && cx<=x2 && cy>=y1 && cy<=y2) return true;
        int px;
        int py;
        if(cx<x1) px=x1;
        else if(cx>x2) px=x2;
        else px=cx;
        if(cy<y1) py=y1;
        else if(cy>y2) py=y2;
        else py=cy;
        if(sqrt(pow((cx-px),2)+pow((cy-py),2))<=radius) return true;
        else return false;
    }
};