    int t;
    scanf("%d",&t);
    while(t--)
    {
        int *a,n,i,j=-1;
        scanf("%d",&n);
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==i+1)
            {
                j=a[i];
                printf("%d ",j);
            }
        }
        if(j==-1)
        {
            printf("Not Found\n");
        }
        else
        {
            printf("\n");
        }
    }
	//code
	return 0;
}
