#include<stdio.h>
#include<math.h>
float divdeterminant(float [][25], float);
void divcofactor(float [][25],float [][25], float);
void divtranspose(float [][25],float [][25], float [][25], float);
void divmultiply(float [25][25],float [25][25],float);
void main()
{
  float first[25][25],a[25][25], k, d;
  int i, j;
  printf("Enter the order of the Matrices : ");
  scanf("%f", &k);
  printf("Enter the elements of first %.0fX%.0f Matrix : \n", k, k);
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
        scanf("%f", &first[i][j]);
        }
    }  
  printf("Enter the elements of second %.0fX%.0f Matrix : \n", k, k);
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
        scanf("%f", &a[i][j]);
        }
    }
  d = divdeterminant(a, k);
  if (d == 0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   divcofactor(first,a, k);
}
 
/*For calculating Determinant of the Matrix */
float divdeterminant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * divdeterminant(b, k - 1));
          s = -1 * s;
          }
    }
 
    return (det);
}
 
void divcofactor(float first[25][25],float num[25][25], float f)
{
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * divdeterminant(b, f - 1);
    }
  }
  divtranspose(first,num, fac, f);
}
/*Finding transpose of matrix*/ 
void divtranspose(float first[25][25],float num[25][25], float fac[25][25], float r)
{
  int i, j;
  float b[25][25], inverse[25][25], d,sum;
 
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = divdeterminant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
    
     divmultiply(first,inverse,r);
    
}
void divmultiply(float first[25][25],float second[25][25],float r){
	int i,j,k;
	float c[25][25],sum;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			sum=0;
			for(k=0;k<r;k++)
			{
				sum=sum+first[i][k]*second[k][j];
			}
			c[i][j]=sum;
		}
	}
	   printf("\n\n\nThe Divided matrix is : \n");
 
   for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         printf("\t%f", c[i][j]);
        }
    printf("\n");
     }
}
