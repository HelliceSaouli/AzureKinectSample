#ifndef __KINECT__
#define __KINECT__

#include <k4a/k4a.hpp>
#include <k4abt.hpp>
#include <opencv2/opencv.hpp>

#include <vector>

class kinect
{
private:
    // Kinect
    k4a::device device;
    k4a::capture capture;
    k4a::calibration calibration;
    k4a_device_configuration_t device_configuration;
    uint32_t device_index;

    // Color
    k4a::image color_image;
    cv::Mat color;

    // Body Tracking
    k4abt::tracker tracker;
    k4abt::frame frame;

    // Skeleton
    std::vector<k4abt_body_t> bodies;

    // Visualize
    std::vector<cv::Vec3b> colors;

public:
    // Constructor
    kinect( const uint32_t index = K4A_DEVICE_DEFAULT );

    // Destructor
    ~kinect();

    // Run
    void run();

    // Update
    void update();

    // Draw
    void draw();

    // Show
    void show();

private:
    // Initialize
    void initialize();

    // Initialize Sensor
    void initialize_sensor();

    // Initialize Body Tracking
    void initialize_body_tracking();

    // Finalize
    void finalize();

    // Update Frame
    void update_frame();

    // Update Body Tracking
    void update_body_tracking();

    // Update Inference
    void update_inference();

    // Update Skeleton
    void update_skeleton();

    // Draw Color
    void draw_color();

    // Show Skeleton
    void show_skeleton();
};

#endif // __KINECT__
