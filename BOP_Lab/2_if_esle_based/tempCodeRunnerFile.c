calculating corrections too make output more correct
	int c1=2-mm,c2=4-mm,c3=6-mm,c4=9-mm,c5=11-mm;
	if(c1<=0) c1+=12;
	if(c2<=0) c2+=12;
	if(c3<=0) c3+=12;
	if(c4<=0) c4+=12;
	if(c5<=0) c5+=12;

		if(months>=c1)
		{
			days-=3;
		}
		if(months>=c2)
		{
			days-=1;
		}
		if(months>=c3)
		{
			days-=1;
		}
		if(months>=c4)
		{
			days-=1;
		}
		if(months>=c5)
		{
			days-=1;
		}
	if(days<0)
	{
		months--;
		days+=31;
		if(months==1)
		{
			days-=3;
		}
		if(months==3)
		{
			days-=1;
		}
		if(months==5)
		{
			days-=1;
		}
		if(months==8)
		{
			days-=1;
		}
		if(months==10)
		{
			days-=1;
		}

		if(months<0)
		{
		years--;
		if(years<0)
			{
			  months=11;
			}
		}
		
	}
