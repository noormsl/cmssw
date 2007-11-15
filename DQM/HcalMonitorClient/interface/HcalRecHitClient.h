#ifndef HcalRecHitClient_H
#define HcalRecHitClient_H

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"
#include "DQMServices/Daemon/interface/MonitorDaemon.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "DQMServices/UI/interface/MonitorUIRoot.h"

#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace cms;
using namespace edm;
using namespace std;

class HcalRecHitClient{

public:

/// Constructor
HcalRecHitClient(const ParameterSet& ps, DaqMonitorBEInterface* dbe_);
HcalRecHitClient();

/// Destructor
virtual ~HcalRecHitClient();

/// Analyze
void analyze(void);

/// BeginJob
void beginJob(void);

/// EndJob
void endJob(void);

/// BeginRun
void beginRun(void);

/// EndRun
void endRun(void);

/// Setup
void setup(void);

/// Cleanup
  void cleanup(void);

  /// HtmlOutput
  void htmlOutput(int run, string htmlDir, string htmlName);
  void getHistograms();
  void loadHistograms(TFile* f);

  void report();
  void errorOutput();
  void getErrors(map<string, vector<QReport*> > out1, map<string, vector<QReport*> > out2, map<string, vector<QReport*> > out3);
  bool hasErrors() const { return dqmReportMapErr_.size(); }
  bool hasWarnings() const { return dqmReportMapWarn_.size(); }
  bool hasOther() const { return dqmReportMapOther_.size(); }

  void resetAllME();
  void createTests();
private:
  int ievt_;
  int jevt_;
  bool subDetsOn_[4];

  bool cloneME_;
  bool verbose_;

  double beamE_thresh_;
  double beamE_width_;
  string process_;
  string baseFolder_;

  //  MonitorUserInterface* mui_;
  DaqMonitorBEInterface* dbe_;

  TH2F* tot_occ_[4];
  TH1F* tot_energy_;

  TH2F* occ_[4];
  TH1F* energy_[4];
  TH1F* energyT_[4];
  TH1F* time_[4];


  // Quality criteria for data integrity
  map<string, vector<QReport*> > dqmReportMapErr_;
  map<string, vector<QReport*> > dqmReportMapWarn_;
  map<string, vector<QReport*> > dqmReportMapOther_;
  map<string, string> dqmQtests_;

};

#endif
