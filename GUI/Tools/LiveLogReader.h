/*
 * This file is part of ElasticFusion.
 *
 * Copyright (C) 2015 Imperial College London
 *
 * The use of the code within this file and all code within files that
 * make up the software that is ElasticFusion is permitted for
 * non-commercial purposes only.  The full terms and conditions that
 * apply to the code within this file are detailed within the LICENSE.txt
 * file and at <http://www.imperial.ac.uk/dyson-robotics-lab/downloads/elastic-fusion/elastic-fusion-license/>
 * unless explicitly stated.  By downloading this file you agree to
 * comply with these terms.
 *
 * If you wish to use any of this code for commercial purposes then
 * please email researchcontracts.engineering@imperial.ac.uk.
 *
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <signal.h>

#include <Utils/Parse.h>

#include "LogReader.h"
#include "OpenNI2Interface.h"
#include "CameraInterface.h"

class LiveLogReader : public LogReader {
 public:
  enum CameraType
  {
    OpenNI2,RealSense
  };
  LiveLogReader(std::string file, bool flipColors, CameraType type);

  virtual ~LiveLogReader();

  void getNext();

  int getNumFrames();

  bool hasMore();

  bool rewind() { return false; }

  void getPrevious() {}

  void fastForward(int frame) {}

  const std::string getFile();

  FrameData getFrameData();

  void setAuto(bool value);

  CameraInterface* asus;

 private:
  cv::Mat depthReadBuffer;
  int64_t lastFrameTime;
  int lastGot;
  FrameData data;
};
