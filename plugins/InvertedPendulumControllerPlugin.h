/* 
 * InvertedPendulumControllerPlugin.h
 *
 * Created on Apr 20, 2020
 *      Author: cameron
 */

#ifndef GAZEBO_INVERTED_PENDULUM_INVERTEDPENDULUMCONTROLLERPLUGIN_H
#define GAZEBO_INVERTED_PENDULUM_INVERTEDPENDULUMCONTROLLERPLUGIN_H

#include "gazebo/gazebo.hh"
#include "gazebo/common/common.hh"
#include "gazebo/physics/physics.hh"
#include "gazebo/transport/Publisher.hh"
#include "gazebo/transport/Connection.hh"

namespace gazebo {

class InvertedPendulumControllerPlugin: public ModelPlugin
{
public:
    void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf) override;

private:

    void OnUpdate();

    double RunController(double ballAngle);

    physics::ModelPtr m_pModel;
    transport::NodePtr m_pNode;
    boost::shared_ptr<physics::Joint> m_pRodJoint;
    transport::PublisherPtr m_pVelocityPublisher;
    event::ConnectionPtr m_pUpdateConnection;

};

GZ_REGISTER_MODEL_PLUGIN(InvertedPendulumControllerPlugin);

}

#endif //GAZEBO_INVERTED_PENDULUM_INVERTEDPENDULUMCONTROLLERPLUGIN_H
