/* 
 * InvertedPendulumControllerPlugin.cpp
 *
 * Created on Apr 20, 2020
 *      Author: cameron
 * Copyright (c) 2020 Symbotic LLC. All rights reserved.
 */

#include "InvertedPendulumControllerPlugin.h"

namespace gazebo {

void InvertedPendulumControllerPlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
{
    m_pModel = _model;
    m_pNode = transport::NodePtr(new transport::Node());
    m_pNode->Init();

    m_pRodJoint = m_pModel->GetJoint("chassis_JOINT_0");
    m_pVelocityPublisher = m_pNode->Advertise<gazebo::msgs::Pose>("/gazebo/default/pioneer2dx_ball/vel_cmd");

    m_pUpdateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&InvertedPendulumControllerPlugin::OnUpdate, this));
}

void InvertedPendulumControllerPlugin::OnUpdate()
{
    if (m_pRodJoint)
    {
        auto jointWorldPose = m_pRodJoint->WorldPose();
        double targetLinearVelocity = RunController(jointWorldPose.Rot().Y());
        msgs::Pose poseMsg;
        poseMsg.mutable_position()->set_x(targetLinearVelocity);
        poseMsg.mutable_position()->set_y(0.0);
        poseMsg.mutable_position()->set_z(0.0);
        poseMsg.mutable_orientation()->set_x(0.0);
        poseMsg.mutable_orientation()->set_y(0.0);
        poseMsg.mutable_orientation()->set_z(0.0);
        poseMsg.mutable_orientation()->set_w(0.0);
        m_pVelocityPublisher->Publish(poseMsg);
    }

}

double InvertedPendulumControllerPlugin::RunController(double ballAngle)
{
    // TODO update this very simple controller
    double gain = 10.0;
    return gain * ballAngle;
}

}