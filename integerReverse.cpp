#define  IDMAX  pow(2,31)-1
#define  IDMIN  -pow(2,31)
class Solution {
public:
   
    int reverse(int x) {
   double procceedData = 0;
	while (x)
	{
		procceedData = procceedData * 10 + x % 10;
		x = x / 10;
	}
	return(procceedData>=IDMAX || procceedData < IDMIN )?  0 :procceedData;//写宏定义更清晰明了
	                                                                       //这样写比ifelse更高级
    }
};