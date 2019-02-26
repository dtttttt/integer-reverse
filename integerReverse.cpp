bool isDataSigned(int InData){
	bool isSigned;
	if (InData > 0)
	{
		isSigned = false;
	}
	else
	{
		isSigned = true;
	}
	return isSigned;
}
int reverse(int x) {
	bool isSigned = FALSE;
	isSigned = isDataSigned(x);
	unsigned int initData = 0;
	if (x == -pow(2, 31))
	{
		x = pow(2, 31);
	}
	else
	{
		initData = abs(x);
	}
	int bitsnum = 0;
	std::vector<int> dataValue;
	for (int i = 0; (unsigned int)(initData / pow(10, i)) > 0; i++)  //这不加unsigned int会跳不出循环！！！ 
	{                                                 //initData / pow(10, i)这个结果是个double型，所以并不是想当然的0
		                                                       //继续除的话会是个小数，依然大于零
		bitsnum++;
		unsigned int element = (unsigned int)(initData / pow(10, i)) % 10;
		dataValue.push_back(element);
	}
    double  procceedData = 0;  //不用double会出错，如果这里是int，输入的是范围内的数，但是反转后超范围了，后面的判断
	                          //是不起作用的
	int num = 0;
	for (std::vector<int>::iterator it = dataValue.begin(); it != dataValue.end(); it++) //咋还是加加！
	{

		procceedData = procceedData + pow(10, (bitsnum-num-1))*(*it);
		num++;

	}
	if (isSigned)
	{
		procceedData = 0 - procceedData;
	}
	if (procceedData>pow(2,31)-1||procceedData<-pow(2,31))  //这题没想到超范围的事
	{
		return 0;
	}
	return procceedData;
}