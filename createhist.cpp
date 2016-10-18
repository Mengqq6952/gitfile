#include"stdio.h"
#include"cv.h"
#include"highgui.h"




    int main( )
    {
        IplImage * src= cvLoadImage("baboon.jpg");
        IplImage* gray_plane = cvCreateImage(cvGetSize(src),8,1);
        cvCvtColor(src,gray_plane,CV_BGR2GRAY);

        int hist_size = 256;
        int hist_height = 256;
        float range[] = {0,255};
        float* ranges[]={range};

        CvHistogram* gray_hist = cvCreateHist(1,&hist_size,CV_HIST_ARRAY,ranges,1);

        cvCalcHist(&gray_plane,gray_hist,0,0);
        IplImage* hist_image = cvCreateImage(cvSize(hist_size*2,hist_height),8,3);
        cvZero(hist_image);
        float max_value = 0;
        cvGetMinMaxHistValue(gray_hist, 0,&max_value,0,0);
        for(int i=0;i<hist_size;i++)
        {
            float bin_val = cvQueryHistValue_1D(gray_hist,i);
            int intensity = cvRound(bin_val*hist_height/max_value);
            cvRectangle(hist_image,
                        cvPoint(i,hist_height-1),
                        cvPoint(i, hist_height - intensity),
                        CV_RGB(255,255,255));
        }
        cvNamedWindow( "GraySource", 1 );
        cvShowImage("GraySource",gray_plane);
        cvNamedWindow( "H-S Histogram", 1 );
        cvShowImage( "H-S Histogram", hist_image );

        cvWaitKey(0);
    }
