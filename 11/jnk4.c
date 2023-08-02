void heapify(a,n,i)
{
	int largest =i;
	int l=(2*i)+1
	int r=(2*i)+2;

	while(l<=n && a[l]>a[r])
		{
			largest=l;
		}
	while(r <=n && a[r]>a[largest])
		{
			largest=r;
		}
	if(largest != i)
	{swap(a[largest],a[i])
		heapify(a,n,largest);	
	}		
}	