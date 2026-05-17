#include "rclcpp/rclcpp.h"
#include "dv_ros2_msgs/EventArray.hpp"

#include <sensor_msgs/Imu.h>

#include <thread>

class CaptureNode : public rclcpp::Node {
public:
    /**
     * Initialize the publishers based on the params.
     */
    CaptureNode();

    /**
     * Stop the running threads
     */
    ~CaptureNode();

    /**
     * Start the threads for reading data
     */
    void startCapture();

    /**
     * Stop the running thread
     */
    void stop();

    /** 
     * Check whether the threads are still reading
     * @return True if the capture threads are still running.
     */
    bool isRunning() const;

private:
    // Publishers
    rclcpp::Publisher<dv_ros2_msgs::msgs::EventArray>::SharedPtr mEventPublisher;
    rclcpp::Publisher<sensor_msgs::msgs::IMUMessage>::SharedPtr mImuPublisher;

    // Thread based things
    std::thread mEventsThread

    /** 
     * Publish the events if mEventsBool is true
     */
}