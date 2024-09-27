////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Logging.hpp>
#include <yq-toolbox/basic/LogFilter.hpp>

#define assetAlert              yAlert("asset")
#define assetCritical           yCritical("asset")
#define assetDebug              yDebug("asset")
#define assetError              yError("asset")
#define assetEmergency          yEmergency("asset")
#define assetFatal              yFatal("asset")
#define assetInfo               yInfo("asset")
#define assetNotice             yNotice("asset")
#define assetWarning            yWarning("asset")

#define glfwAlert               yAlert("glfw")
#define glfwCritical            yCritical("glfw")
#define glfwDebug               yDebug("glfw")
#define glfwError               yError("glfw")
#define glfwEmergency           yEmergency("glfw")
#define glfwFatal               yFatal("glfw")
#define glfwInfo                yInfo("glfw")
#define glfwNotice              yNotice("glfw")
#define glfwWarning             yWarning("glfw")

#define tachyonAlert            yAlert("tachyon")
#define tachyonCritical         yCritical("tachyon")
#define tachyonDebug            yDebug("tachyon")
#define tachyonError            yError("tachyon")
#define tachyonEmergency        yEmergency("tachyon")
#define tachyonFatal            yFatal("tachyon")
#define tachyonInfo             yInfo("tachyon")
#define tachyonNotice           yNotice("tachyon")
#define tachyonWarning          yWarning("tachyon")

#define viewAlert               yAlert("view")
#define viewCritical            yCritical("view")
#define viewDebug               yDebug("view")
#define viewError               yError("view")
#define viewEmergency           yEmergency("view")
#define viewFatal               yFatal("view")
#define viewInfo                yInfo("view")
#define viewNotice              yNotice("view")
#define viewWarning             yWarning("view")

#define vizAlert                yAlert("viz")
#define vizCritical             yCritical("viz")
#define vizDebug                yDebug("viz")
#define vizError                yError("viz")
#define vizEmergency            yEmergency("viz")
#define vizFatal                yFatal("viz")
#define vizInfo                 yInfo("viz")
#define vizNotice               yNotice("viz")
#define vizWarning              yWarning("viz")

#define vizFirstAlert(...)      yLogFirstAlert("viz", __VA_ARGS__)
#define vizFirstCritical(...)   yLogFirstCritical("viz", __VA_ARGS__)
#define vizFirstDebug(...)      yLogFirstDebug("viz", __VA_ARGS__)
#define vizFirstError(...)      yLogFirstError("viz", __VA_ARGS__)
#define vizFirstEmergency(...)  yLogFirstEmergency("viz", __VA_ARGS__)
#define vizFirstFatal(...)      yLogFirstFatal("viz", __VA_ARGS__)
#define vizFirstInfo(...)       yLogFirstInfo("viz", __VA_ARGS__)
#define vizFirstNotice(...)     yLogFirstNotice("viz", __VA_ARGS__)
#define vizFirstWarning(...)    yLogFirstWarning("viz", __VA_ARGS__)

#define vqAlert                 yAlert("vq")
#define vqCritical              yCritical("vq")
#define vqDebug                 yDebug("vq")
#define vqError                 yError("vq")
#define vqEmergency             yEmergency("vq")
#define vqFatal                 yFatal("vq")
#define vqInfo                  yInfo("vq")
#define vqNotice                yNotice("vq")
#define vqWarning               yWarning("vq")

#define vqFirstAlert(...)       yLogFirstAlert("vq", __VA_ARGS__)
#define vqFirstCritical(...)    yLogFirstCritical("vq", __VA_ARGS__)
#define vqFirstDebug(...)       yLogFirstDebug("vq", __VA_ARGS__)
#define vqFirstError(...)       yLogFirstError("vq", __VA_ARGS__)
#define vqFirstEmergency(...)   yLogFirstEmergency("vq", __VA_ARGS__)
#define vqFirstFatal(...)       yLogFirstFatal("vq", __VA_ARGS__)
#define vqFirstInfo(...)        yLogFirstInfo("vq", __VA_ARGS__)
#define vqFirstNotice(...)      yLogFirstNotice("vq", __VA_ARGS__)
#define vqFirstWarning(...)     yLogFirstWarning("vq", __VA_ARGS__)
