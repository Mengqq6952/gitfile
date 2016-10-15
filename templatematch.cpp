#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "stdio.h"


int main(int argc,char **argv)
{
IplImage *src ,*templ,*ftmp[6];
int i;
src=cvLoadImage("src.jpg",1);
templ=cvLoadImage("templ.jpg",1);
int iwidth=src->width - templ->width +1;
int iheight=src->height - templ->height +1;
for(i=0;i<6;i++)
{
ftmp[i]=cvCreateImage(cvSize(iwidth,iheight),32,1);
cvMatchTemplate(src,templ,ftmp[i],i);
cvNormalize(ftmp[i],ftmp[i],1,0,CV_MINMAX);
}
cvNamedWindow("Template",0);
cvShowImage("Template",templ);
cvNamedWindow("Image",0);
cvShowImage("Image",src);
cvNamedWindow("SQDIFF",0);
cvShowImage("SQDIFF",ftmp[0]);
cvNamedWindow("SQDIFF_NORMED",0);
cvShowImage("SQDIFF_NORMED",ftmp[1]);
cvNamedWindow("CCORR",0);
cvShowImage("CCORR",ftmp[2]);
cvNamedWindow("CCORR_NORMED",0);
cvShowImage("CCORR_NORMED",ftmp[3]);
cvNamedWindow("CCOEFF",0);
cvShowImage("CCOEFF",ftmp[4]);
cvNamedWindow("CCOEFF_NORMED",0);
cvShowImage("CCOEFF_NORMED",ftmp[5]);
cvWaitKey(0);



}
