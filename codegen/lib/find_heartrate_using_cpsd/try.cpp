#include "find_heartrate_using_cpsd.cpp"
#include<highgui.h>
#include<cv.h>
#include<fstream>
#include<time.h>
using namespace std;
using namespace cv;
int main()
{
time_t timer1,timer2;
double dat[101];
VideoCapture cap=VideoCapture(0);
Mat frame,channels[3];
ofstream f;
f.open("op.txt");
Scalar m,s;
int v[3];
int i=0;
time(&timer1);
while(i<=100)
{
i++;
cap>>frame;

//if (c=='x')
//break;

split(frame,channels);


//imshow("window",frame);
//imshow("r",channels[2]);
//imshow("g",channels[1]);
//imshow("b",channels[0]);
meanStdDev(frame,m,s);
//cout<<"Mean "<<m<<endl;
//cout<<"Standard "<<s<<endl;
cout<<i<<endl;
//v[0]=channels[0].at<uchar>(frame.rows/2,frame.cols/2);
//v[1]=channels[1].at<uchar>(frame.rows/2,frame.cols/2);
//v[2]=channels[2].at<uchar>(frame.rows/2,frame.cols/2);
channels[0]=(channels[0]-m[0])/s[0];
channels[1]=(channels[1]-m[1])/s[1];
channels[2]=(channels[2]-m[2])/s[2];
f<<mean(channels[0])[0]<<",";
f<<mean(channels[1])[0]<<",";
dat[i]=mean(channels[1])[0];
f<<mean(channels[2])[0]<<endl;

}
time(&timer2);
cout<<difftime(timer2,timer1)<<endl;
double hrtrate_data[4096];
int32_T hrtrate_sizes[1];
find_heartrate_using_cpsd(dat,100/difftime(timer2,timer1),hrtrate_data,hrtrate_sizes);
cout<<hrtrate_data[0]<<endl;
}
