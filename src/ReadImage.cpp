#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_publisher");

		
  ros::NodeHandle nh;
	ros::NodeHandle _nh("~"); // to get the private params
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("image_raw", 1);
	cv::Mat image;


	if(argc > 1 ){
		image	= cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
	}
	else{
		std::string caminho_arquivo_fonte;		
		_nh.getParam("caminho_arquivo_fonte", caminho_arquivo_fonte);
		image	= cv::imread(caminho_arquivo_fonte.c_str(), CV_LOAD_IMAGE_COLOR);
	}

   
  cv::waitKey(30);
  sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

  ros::Rate loop_rate(5);
  while (nh.ok()) {
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
