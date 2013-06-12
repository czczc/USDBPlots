// From Xin Qian & Jiajie Ling

double div_err(double a, double a_err, double b, double b_err) {

  double a_rel_err = a_err / a;
  double b_rel_err = b_err / b;
  double ratio = a/b;
  double ratio_rel_err = sqrt(a_rel_err*a_rel_err + b_rel_err*b_rel_err);
  return ratio * ratio_rel_err;
}

double res_fun(double *x, double *par) {
  return sqrt( par[0]*par[0] + par[1]*par[1]/(*x) + par[2]*par[2]/(*x)/(*x));
}

void plot(const char* type = "eps") {
  gROOT->ProcessLine(".x ../../style.C");
  const int N = 9;
  const int M = 4;

  double Erec_Alpha[M] = {
    1.21738, // alpha
    9.74580e-01, // alpha
    9.10940e-01, // alpha
    7.94825e-01 // alpha
  };

  double errErec_Alpha[M] = {
    1.02623e-04,
    3.60321e-04,
    7.14174e-05,
    1.16201e-04
  };

  double Res_Alpha[M] = {
    8.89032e-02,
    7.87709e-02,
    7.73245e-02,
    7.06278e-02
  };

  double errRes_Alpha[M] = {
    9.34051e-05,
    4.16611e-04,
    8.21045e-05,
    1.62120e-04
  };

  double Erec[N] = {
    6.27196e-01, // Cs137
    8.08796e-01, // Mn
    9.65036e-01, // Ge68
    1.44833e+00, // K40
    2.26770e+00, // nH
    2.44897e+00, // Co
    5.07152e+00, // nC
    6.29008e+00, // O*
    7.84922e+00  // nGd
  };

  double errErec[N] = {
    4.42500000000012328e-04, // Cs137
    7.71999999999994913e-04, // Mn
    8.14750000000002972e-03, // Ge68
    9.73337e-04, // K40
    8.95000e-05, // nH
    3.01274e-04, // Co
    4.19104e-03, // nC
    3.07897e-04, // O*
    8.98361e-05  // nGd
  };

  double Res[N] = {
    7.36898500000000012e-02, // Cs137
    8.35386499999999921e-02, // Mn
    9.46442559455687449e-02, // Ge68
    1.11633e-01, // K40
    1.29452e-01, // nH
    1.38453e-01, // Co
    2.22988e-01, // nC
    2.15981e-01, // O*
    2.59885e-01  // nGd
  };

  double errRes[N] = {
    4.48950000000003513e-04,
    7.71999999999994913e-04,
    1.12200999999999967e-02,
    1.04994e-03,
    7.53137e-05,
    2.36671e-04,
    1.70469999999999927e-02,
    2.94347e-04,
    7.88013e-05
  };

  double Erec_SN[3] = {2.29844e+00, 5.08367e+00, 7.94773e+00};
  double errErec_SN[3] = {8.33143e-04, 2.74914e-02, 6.23405e-04};
  double Res_SN[3] = {1.35773e-01, 1.79107e-01, 2.76127e-01};
  double errRes_SN[3] = {8.70193e-04, 2.86370e-02, 5.87815e-04};

  double Erec_IBD[1] = {7.91436e+00};
  double errErec_IBD[1] = {1.36986e-03};
  double Res_IBD[1] = {2.86247e-01};
  double errRes_IBD[1] = {1.37766e-03};

  for (int i=0; i<N; i++) {
    errRes[i] = div_err(Res[i], errRes[i], Erec[i], errErec[i]);
    Res[i] /= Erec[i];
  }

  for (int i=0; i<N; i++) {
    Res[i] = sqrt( Res[i]*Res[i] + 0.0125*0.0125);
    errRes[i] = sqrt(errRes[i]*errRes[i] + 0.0025*0.0025);
  }

  for (int i=0; i<M; i++) {
    errRes_Alpha[i] = div_err(Res_Alpha[i], errRes_Alpha[i], Erec_Alpha[i], errErec_Alpha[i]);
    Res_Alpha[i] /= Erec_Alpha[i];

    Erec_Alpha[i] *= 1./0.8;
  }

  for (int i=0; i<3; i++) {
    errRes_SN[i] = div_err(Res_SN[i], errRes_SN[i], Erec_SN[i], errErec_SN[i]);
    Res_SN[i] /= Erec_SN[i];
  }

  for (int i=0; i<1; i++) {
    errRes_IBD[i] = div_err(Res_IBD[i], errRes_IBD[i], Erec_IBD[i], errErec_IBD[i]);
    Res_IBD[i] /= Erec_IBD[i];
  }

  TGraphErrors *gr = new TGraphErrors(N, Erec, Res, errErec, errRes);
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1.5);
  gr->SetMarkerColor(1);
  gr->SetLineColor(1);

  TGraphErrors *gr2 = new TGraphErrors(M, Erec_Alpha, Res_Alpha, errErec_Alpha, errRes_Alpha);
  gr2->SetMarkerStyle(21);
  gr2->SetMarkerSize(1.5);
  gr2->SetMarkerColor(2);
  gr2->SetLineColor(2);

  TGraphErrors *gr3 = new TGraphErrors(3, Erec_SN, Res_SN, errErec_SN, errRes_SN);
  gr3->SetMarkerStyle(22);
  gr3->SetMarkerSize(1.5);
  gr3->SetMarkerColor(4);
  gr3->SetLineColor(4);

  TGraphErrors *gr4 = new TGraphErrors(1, Erec_IBD, Res_IBD, errErec_IBD, errRes_IBD);
  gr4->SetMarkerStyle(23);
  gr4->SetMarkerSize(1.5);
  gr4->SetMarkerColor(6);
  gr4->SetLineColor(6);


  TF1 *f1 = new TF1("f1", res_fun, 0.1, 8, 3);
  f1->SetParameter(0, 1.53664e-02);
  f1->SetParameter(1, 8.11235e-02);
  f1->SetParameter(2, 3.34116e-02);
  // f1->SetRange(0.6, 9);
  f1->SetLineColor(2);

  TF1 *f2 = new TF1("f2", res_fun, 0.1, 8, 3);
  f2->SetParameter(0, sqrt(1.82e-4));
  f2->SetParameter(1, sqrt(6.288e-3));
  f2->SetParameter(2, sqrt(2.633e-3));

  f2->SetLineColor(4);

  TF1 *f3 = new TF1("f3", res_fun, 0.1, 8, 3);
  f3->SetParameter(0, 0.022);
  f3->SetParameter(1, 0.079);
  f3->SetParameter(2, 0.016);
  f3->SetLineColor(1);

  TCanvas c1("c1", "c1", 800, 600);
  gr->Draw("ap");
  gr->GetYaxis()->SetRangeUser(0,0.15);
  gr->SetTitle("Energy Resolution");
  gr->GetXaxis()->SetTitle("E_{rec} [MeV]");
  gr->GetYaxis()->SetTitle("#sigma_{E} / E");
  gr->Fit("f1");

  //f1->SetParameter(0, f1->GetParameter(0)*1.2);

  // f1->Draw("same");
  //f2->Draw("same");
  //f3->Draw("same");
  //gr2->Draw("p,same");
  gr3->Draw("p,same");
  gr4->Draw("p,same");

  // c1->Print("gamma_res2.png");
  TString name("Resolution");
  c1.SaveAs(name + ".eps");
  c1.SaveAs(name + ".pdf");
  c1.SaveAs(name + ".png");

  TString extra(type);
  if (! (extra == "eps" || extra == "pdf" || extra == "png")) {
    c1.SaveAs(name + "." + type);
  }
}

