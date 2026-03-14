// My approach but chatGPT coded

class Solution {
public:
    int countPoints(string rings) {
        int count = 0;

        for(int rod = 0; rod <= 9; rod++) {

            bool red = false;
            bool green = false;
            bool blue = false;

            for(int i = 0; i < rings.size(); i += 2) {

                char color = rings[i];
                int pos = rings[i+1] - '0';

                if(pos == rod) {
                    if(color == 'R') red = true;
                    if(color == 'G') green = true;
                    if(color == 'B') blue = true;
                }
            }

            if(red && green && blue) {
                count++;
            }
        }

        return count;
    }
};