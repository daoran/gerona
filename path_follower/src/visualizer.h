#ifndef VISUALIZER_H
#define VISUALIZER_H

/// STL
#include <string>

/// ROS
#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>

/**
 * @brief Provides functions to visualize things in Rviz (e.g. arrows, lines, ...)
 *
 * This is a singleton class. This means, there is only one instance of the class, which is accessable from everywhere.
 * To get a pointer to this instance use the following code:
 *
 * <code>
 *    Visualizer *vis = Visualizer::getInstance();
 * </code>
 */
class Visualizer
{
public:
    //! Get a pointer to the Visualizer object.
    static Visualizer* getInstance();

    /**
     * @brief Check if there are any subscribers to the markers.
     *
     * There is no need to publish markers, as long as nobody subscribes for them. This method can be used to check this,
     * before doing computations for the markers.
     *
     * @return true if there is at least one subscriber.
     */
    bool hasSubscriber();

    /**
     * @brief Publish an arrow marker.
     * @param id    ID of the marker.
     * @param pose  Pose of the arrow (position and pointing direction)
     * @param ns    Namespace of the marker.
     * @param r     Marker color, red.
     * @param g     Marker color, green.
     * @param b     Marker color, blue.
     * @param live  Lifetime of the marker.
     */
    void drawArrow(int id, const geometry_msgs::Pose &pose, const std::string& ns, float r, float g, float b, double live = 3) const;

    /**
     * @brief Publish a line marker.
     * @param id    ID of the marker.
     * @param from  Start point of the line.
     * @param to    End point of the line.
     * @param frame TF-frame in which the line is placed.
     * @param ns    Namespace of the marker.
     * @param r     Marker color, red.
     * @param g     Marker color, green.
     * @param b     Marker color, blue.
     * @param live  Lifetime of the marker.
     * @param scale Thickness of the line.
     */
    void drawLine(int id, const geometry_msgs::Point &from, const geometry_msgs::Point &to, const std::string &frame,
                  const std::string& ns, float r, float g, float b, double live = 3, float scale = 0.3) const;

    /**
     * @brief Publish a circle marker.
     * @param id      ID of the marker.
     * @param center  Center of the circle.
     * @param radius  Radius of the circle.
     * @param frame   TF-frame in which the marker is placed.
     * @param ns      Namespace of the marker.
     * @param r       Marker color, red.
     * @param g       Marker color, green.
     * @param b       Marker color, blue.
     * @param live    Lifetime of the marker.
     */
    void drawCircle(int id, const geometry_msgs::Point &center, double radius, const std::string &frame,
                    const std::string& ns, float r, float g, float b, double live = 3) const;

    /**
     * @brief Publish a simple marker to visualize a single point.
     * @param id    ID of the marker.
     * @param pos   Position of the marker.
     * @param ns    Namespace of the marker.
     * @param r     Marker color, red.
     * @param g     Marker color, green.
     * @param b     Marker color, blue.
     */
    void drawMark(int id, const geometry_msgs::Point &pos, const std::string& ns, float r, float g, float b) const;

private:
    ros::NodeHandle private_nh_;
    ros::Publisher vis_pub_;

    Visualizer();
};

#endif // VISUALIZER_H