#ifndef CPPAD_CG_TEST_DISTILLATION_INCLUDED
#define CPPAD_CG_TEST_DISTILLATION_INCLUDED

/* --------------------------------------------------------------------------
 *  CppADCodeGen: C++ Algorithmic Differentiation with Source Code Generation:
 *    Copyright (C) 2013 Ciengis
 *
 *  CppADCodeGen is distributed under multiple licenses:
 *
 *   - Eclipse Public License Version 1.0 (EPL1), and
 *   - GNU General Public License Version 3 (GPL3).
 *
 *  EPL1 terms and conditions can be found in the file "epl-v10.txt", while
 *  terms and conditions for the GPL3 can be found in the file "gpl3.txt".
 * ----------------------------------------------------------------------------
 * Author: Joao Leal
 */

namespace CppAD {
namespace cg {

template<class Base>
inline CppAD::ADFun<Base>* Distillation(std::vector<DaeVarInfo>& daeVar,
                                        const std::vector<double>& x) {
    using namespace CppAD;
    using namespace std;
    using ADB = CppAD::AD<Base>;

    std::vector<ADB> U(81);
    assert(U.size() == x.size());
    for (size_t i = 0; i < x.size(); i++) {
        U[i] = x[i];
    }
    Independent(U);

    // dependent variable vector
    std::vector<ADB> res(48);
    std::vector<ADB> v(66);

    daeVar.resize(81);
    daeVar[0] = DaeVarInfo("mWater__0");
    const ADB& mWater__0 = U[0];
    daeVar[1] = DaeVarInfo("mWater__1");
    const ADB& mWater__1 = U[1];
    daeVar[2] = DaeVarInfo("mWater__2");
    const ADB& mWater__2 = U[2];
    daeVar[3] = DaeVarInfo("mWater__3");
    const ADB& mWater__3 = U[3];
    daeVar[4] = DaeVarInfo("mWater__4");
    const ADB& mWater__4 = U[4];
    daeVar[5] = DaeVarInfo("mWater__5");
    const ADB& mWater__5 = U[5];
    daeVar[6] = DaeVarInfo("mWater__6");
    const ADB& mWater__6 = U[6];
    daeVar[7] = DaeVarInfo("mWater__7");
    const ADB& mWater__7 = U[7];
    daeVar[8] = DaeVarInfo("mEthanol__0");
    const ADB& mEthanol__0 = U[8];
    daeVar[9] = DaeVarInfo("mEthanol__1");
    const ADB& mEthanol__1 = U[9];
    daeVar[10] = DaeVarInfo("mEthanol__2");
    const ADB& mEthanol__2 = U[10];
    daeVar[11] = DaeVarInfo("mEthanol__3");
    const ADB& mEthanol__3 = U[11];
    daeVar[12] = DaeVarInfo("mEthanol__4");
    const ADB& mEthanol__4 = U[12];
    daeVar[13] = DaeVarInfo("mEthanol__5");
    const ADB& mEthanol__5 = U[13];
    daeVar[14] = DaeVarInfo("mEthanol__6");
    const ADB& mEthanol__6 = U[14];
    daeVar[15] = DaeVarInfo("mEthanol__7");
    const ADB& mEthanol__7 = U[15];
    daeVar[16] = DaeVarInfo("T__0");
    const ADB& T__0 = U[16];
    daeVar[17] = DaeVarInfo("T__1");
    const ADB& T__1 = U[17];
    daeVar[18] = DaeVarInfo("T__2");
    const ADB& T__2 = U[18];
    daeVar[19] = DaeVarInfo("T__3");
    const ADB& T__3 = U[19];
    daeVar[20] = DaeVarInfo("T__4");
    const ADB& T__4 = U[20];
    daeVar[21] = DaeVarInfo("T__5");
    const ADB& T__5 = U[21];
    daeVar[22] = DaeVarInfo("T__6");
    const ADB& T__6 = U[22];
    daeVar[23] = DaeVarInfo("T__7");
    const ADB& T__7 = U[23];
    daeVar[24] = DaeVarInfo("yWater__0");
    const ADB& yWater__0 = U[24];
    daeVar[25] = DaeVarInfo("yWater__1");
    const ADB& yWater__1 = U[25];
    daeVar[26] = DaeVarInfo("yWater__2");
    const ADB& yWater__2 = U[26];
    daeVar[27] = DaeVarInfo("yWater__3");
    const ADB& yWater__3 = U[27];
    daeVar[28] = DaeVarInfo("yWater__4");
    const ADB& yWater__4 = U[28];
    daeVar[29] = DaeVarInfo("yWater__5");
    const ADB& yWater__5 = U[29];
    daeVar[30] = DaeVarInfo("yWater__6");
    const ADB& yWater__6 = U[30];
    daeVar[31] = DaeVarInfo("yWater__7");
    const ADB& yWater__7 = U[31];
    daeVar[32] = DaeVarInfo("yEthanol__0");
    const ADB& yEthanol__0 = U[32];
    daeVar[33] = DaeVarInfo("yEthanol__1");
    const ADB& yEthanol__1 = U[33];
    daeVar[34] = DaeVarInfo("yEthanol__2");
    const ADB& yEthanol__2 = U[34];
    daeVar[35] = DaeVarInfo("yEthanol__3");
    const ADB& yEthanol__3 = U[35];
    daeVar[36] = DaeVarInfo("yEthanol__4");
    const ADB& yEthanol__4 = U[36];
    daeVar[37] = DaeVarInfo("yEthanol__5");
    const ADB& yEthanol__5 = U[37];
    daeVar[38] = DaeVarInfo("yEthanol__6");
    const ADB& yEthanol__6 = U[38];
    daeVar[39] = DaeVarInfo("yEthanol__7");
    const ADB& yEthanol__7 = U[39];
    daeVar[40] = DaeVarInfo("V__0");
    const ADB& V__0 = U[40];
    daeVar[41] = DaeVarInfo("V__1");
    const ADB& V__1 = U[41];
    daeVar[42] = DaeVarInfo("V__2");
    const ADB& V__2 = U[42];
    daeVar[43] = DaeVarInfo("V__3");
    const ADB& V__3 = U[43];
    daeVar[44] = DaeVarInfo("V__4");
    const ADB& V__4 = U[44];
    daeVar[45] = DaeVarInfo("V__5");
    const ADB& V__5 = U[45];
    daeVar[46] = DaeVarInfo("V__6");
    const ADB& V__6 = U[46];
    daeVar[47] = DaeVarInfo("Qc");
    const ADB& Qc = U[47];
    daeVar[48] = DaeVarInfo("Qsteam");
    daeVar[48].makeConstant();
    const ADB& Qsteam = U[48];
    daeVar[49] = DaeVarInfo("Fdistillate");
    daeVar[49].makeConstant();
    const ADB& Fdistillate = U[49];
    daeVar[50] = DaeVarInfo("reflux");
    daeVar[50].makeConstant();
    const ADB& reflux = U[50];
    daeVar[51] = DaeVarInfo("Frectifier");
    daeVar[51].makeConstant();
    const ADB& Frectifier = U[51];
    daeVar[52] = DaeVarInfo("feed");
    daeVar[52].makeConstant();
    const ADB& feed = U[52];
    daeVar[53] = DaeVarInfo("P");
    daeVar[53].makeConstant();
    const ADB& P = U[53];
    daeVar[54] = DaeVarInfo("xFWater");
    daeVar[54].makeConstant();
    const ADB& xFWater = U[54];
    daeVar[55] = DaeVarInfo("Tfeed");
    daeVar[55].makeConstant();
    const ADB& Tfeed = U[55];
    daeVar[56].makeIntegratedVariable();
    daeVar[57] = 0;
    const ADB& dmWater__0dt = U[57];
    daeVar[58] = 1;
    const ADB& dmWater__1dt = U[58];
    daeVar[59] = 2;
    const ADB& dmWater__2dt = U[59];
    daeVar[60] = 3;
    const ADB& dmWater__3dt = U[60];
    daeVar[61] = 4;
    const ADB& dmWater__4dt = U[61];
    daeVar[62] = 5;
    const ADB& dmWater__5dt = U[62];
    daeVar[63] = 6;
    const ADB& dmWater__6dt = U[63];
    daeVar[64] = 7;
    const ADB& dmWater__7dt = U[64];
    daeVar[65] = 8;
    const ADB& dmEthanol__0dt = U[65];
    daeVar[66] = 9;
    const ADB& dmEthanol__1dt = U[66];
    daeVar[67] = 10;
    const ADB& dmEthanol__2dt = U[67];
    daeVar[68] = 11;
    const ADB& dmEthanol__3dt = U[68];
    daeVar[69] = 12;
    const ADB& dmEthanol__4dt = U[69];
    daeVar[70] = 13;
    const ADB& dmEthanol__5dt = U[70];
    daeVar[71] = 14;
    const ADB& dmEthanol__6dt = U[71];
    daeVar[72] = 15;
    const ADB& dmEthanol__7dt = U[72];
    daeVar[73] = 16;
    const ADB& dT__0dt = U[73];
    daeVar[74] = 17;
    const ADB& dT__1dt = U[74];
    daeVar[75] = 18;
    const ADB& dT__2dt = U[75];
    daeVar[76] = 19;
    const ADB& dT__3dt = U[76];
    daeVar[77] = 20;
    const ADB& dT__4dt = U[77];
    daeVar[78] = 21;
    const ADB& dT__5dt = U[78];
    daeVar[79] = 22;
    const ADB& dT__6dt = U[79];
    daeVar[80] = 23;
    const ADB& dT__7dt = U[80];

    v[0] = yWater__1 * V__0;
    v[1] = mWater__0 / (mWater__0 + mEthanol__0);
    v[2] = reflux * Fdistillate;
    v[3] = v[1] * v[2];
    res[0] = v[0] - v[3] - v[1] * Fdistillate - dmWater__0dt;
    v[4] = yWater__2 * V__1;
    v[5] = mWater__1 / (mWater__1 + mEthanol__1);
    v[6] = 0.018015283300000001 * mWater__1;
    v[7] = v[6] + 0.046068440000000002 * mEthanol__1;
    v[6] = v[6] / v[7];
    v[8] = 1 - v[6];
    v[9] = 1 / (v[6] / (0.018015283300000001 * 1000 * (-13.851000000000001 + 0.64037999999999995 * T__1 + -0.00191 * T__1 * T__1 + 1.8211e-06 * T__1 * T__1 * T__1)) + v[8] / (0.046068440000000002 * 1000 * 1.6288 / pow(0.27468999999999999, 1 + pow(1 - T__1 / 514, 0.23178000000000001))));
    v[10] = (v[7] / v[9]) / 0.78539816339744828 - 0.20000000000000001;
    v[11] = 1 - v[5];
    v[10] = (0.59999999999999998 * pow(((v[10] + sqrt(0.0001 + v[10] * v[10])) / 2) / 0.66400000000000003, 1.5) * v[9]) / (0.018015283300000001 * v[5] + 0.046068440000000002 * v[11]);
    v[9] = v[5] * v[10];
    res[1] = v[3] + v[4] - v[9] - v[0] - dmWater__1dt;
    v[12] = yWater__3 * V__2;
    v[13] = mWater__2 / (mWater__2 + mEthanol__2);
    v[14] = 0.018015283300000001 * mWater__2;
    v[15] = v[14] + 0.046068440000000002 * mEthanol__2;
    v[14] = v[14] / v[15];
    v[16] = 1 - v[14];
    v[17] = 1 / (v[14] / (0.018015283300000001 * 1000 * (-13.851000000000001 + 0.64037999999999995 * T__2 + -0.00191 * T__2 * T__2 + 1.8211e-06 * T__2 * T__2 * T__2)) + v[16] / (0.046068440000000002 * 1000 * 1.6288 / pow(0.27468999999999999, 1 + pow(1 - T__2 / 514, 0.23178000000000001))));
    v[18] = (v[15] / v[17]) / 0.78539816339744828 - 0.20000000000000001;
    v[19] = 1 - v[13];
    v[18] = (0.59999999999999998 * pow(((v[18] + sqrt(0.0001 + v[18] * v[18])) / 2) / 0.66400000000000003, 1.5) * v[17]) / (0.018015283300000001 * v[13] + 0.046068440000000002 * v[19]);
    v[17] = v[13] * v[18];
    res[2] = v[12] + v[9] - v[17] - v[4] - dmWater__2dt;
    v[20] = yWater__4 * V__3;
    v[21] = mWater__3 / (mWater__3 + mEthanol__3);
    v[22] = 0.018015283300000001 * mWater__3;
    v[23] = v[22] + 0.046068440000000002 * mEthanol__3;
    v[22] = v[22] / v[23];
    v[24] = 1 - v[22];
    v[25] = 1 / (v[22] / (0.018015283300000001 * 1000 * (-13.851000000000001 + 0.64037999999999995 * T__3 + -0.00191 * T__3 * T__3 + 1.8211e-06 * T__3 * T__3 * T__3)) + v[24] / (0.046068440000000002 * 1000 * 1.6288 / pow(0.27468999999999999, 1 + pow(1 - T__3 / 514, 0.23178000000000001))));
    v[26] = (v[23] / v[25]) / 0.78539816339744828 - 0.20000000000000001;
    v[27] = 1 - v[21];
    v[26] = (0.59999999999999998 * pow(((v[26] + sqrt(0.0001 + v[26] * v[26])) / 2) / 0.66400000000000003, 1.5) * v[25]) / (0.018015283300000001 * v[21] + 0.046068440000000002 * v[27]);
    v[25] = v[21] * v[26];
    res[3] = v[17] + v[20] - v[25] - v[12] - dmWater__3dt;
    v[28] = yWater__5 * V__4;
    v[29] = xFWater * feed;
    v[30] = mWater__4 / (mWater__4 + mEthanol__4);
    v[31] = 0.018015283300000001 * mWater__4;
    v[32] = v[31] + 0.046068440000000002 * mEthanol__4;
    v[31] = v[31] / v[32];
    v[33] = 1 - v[31];
    v[34] = 1 / (v[31] / (0.018015283300000001 * 1000 * (-13.851000000000001 + 0.64037999999999995 * T__4 + -0.00191 * T__4 * T__4 + 1.8211e-06 * T__4 * T__4 * T__4)) + v[33] / (0.046068440000000002 * 1000 * 1.6288 / pow(0.27468999999999999, 1 + pow(1 - T__4 / 514, 0.23178000000000001))));
    v[35] = (v[32] / v[34]) / 0.78539816339744828 - 0.20000000000000001;
    v[36] = 1 - v[30];
    v[35] = (0.59999999999999998 * pow(((v[35] + sqrt(0.0001 + v[35] * v[35])) / 2) / 0.66400000000000003, 1.5) * v[34]) / (0.018015283300000001 * v[30] + 0.046068440000000002 * v[36]);
    v[34] = v[30] * v[35];
    res[4] = v[25] + v[28] + v[29] - v[34] - v[20] - dmWater__4dt;
    v[37] = yWater__6 * V__5;
    v[38] = mWater__5 / (mWater__5 + mEthanol__5);
    v[39] = 0.018015283300000001 * mWater__5;
    v[40] = v[39] + 0.046068440000000002 * mEthanol__5;
    v[39] = v[39] / v[40];
    v[41] = 1 - v[39];
    v[42] = 1 / (v[39] / (0.018015283300000001 * 1000 * (-13.851000000000001 + 0.64037999999999995 * T__5 + -0.00191 * T__5 * T__5 + 1.8211e-06 * T__5 * T__5 * T__5)) + v[41] / (0.046068440000000002 * 1000 * 1.6288 / pow(0.27468999999999999, 1 + pow(1 - T__5 / 514, 0.23178000000000001))));
    v[43] = (v[40] / v[42]) / 0.78539816339744828 - 0.20000000000000001;
    v[44] = 1 - v[38];
    v[43] = (0.59999999999999998 * pow(((v[43] + sqrt(0.0001 + v[43] * v[43])) / 2) / 0.66400000000000003, 1.5) * v[42]) / (0.018015283300000001 * v[38] + 0.046068440000000002 * v[44]);
    v[42] = v[38] * v[43];
    res[5] = v[34] + v[37] - v[28] - v[42] - dmWater__5dt;
    v[45] = yWater__7 * V__6;
    v[46] = mWater__6 / (mWater__6 + mEthanol__6);
    v[47] = 0.018015283300000001 * mWater__6;
    v[48] = v[47] + 0.046068440000000002 * mEthanol__6;
    v[47] = v[47] / v[48];
    v[49] = 1 - v[47];
    v[50] = 1 / (v[47] / (0.018015283300000001 * 1000 * (-13.851000000000001 + 0.64037999999999995 * T__6 + -0.00191 * T__6 * T__6 + 1.8211e-06 * T__6 * T__6 * T__6)) + v[49] / (0.046068440000000002 * 1000 * 1.6288 / pow(0.27468999999999999, 1 + pow(1 - T__6 / 514, 0.23178000000000001))));
    v[51] = (v[48] / v[50]) / 0.78539816339744828 - 0.20000000000000001;
    v[52] = 1 - v[46];
    v[51] = (0.59999999999999998 * pow(((v[51] + sqrt(0.0001 + v[51] * v[51])) / 2) / 0.66400000000000003, 1.5) * v[50]) / (0.018015283300000001 * v[46] + 0.046068440000000002 * v[52]);
    v[50] = v[46] * v[51];
    res[6] = v[42] + v[45] - v[50] - v[37] - dmWater__6dt;
    v[53] = mWater__7 / (mWater__7 + mEthanol__7);
    res[7] = v[50] - v[53] * Frectifier - v[45] - dmWater__7dt;
    v[54] = yEthanol__1 * V__0;
    v[55] = 1 - v[1];
    v[2] = v[55] * v[2];
    res[8] = v[54] - v[2] - v[55] * Fdistillate - dmEthanol__0dt;
    v[56] = yEthanol__2 * V__1;
    v[10] = v[11] * v[10];
    res[9] = v[2] + v[56] - v[10] - v[54] - dmEthanol__1dt;
    v[57] = yEthanol__3 * V__2;
    v[18] = v[19] * v[18];
    res[10] = v[57] + v[10] - v[18] - v[56] - dmEthanol__2dt;
    v[58] = yEthanol__4 * V__3;
    v[26] = v[27] * v[26];
    res[11] = v[18] + v[58] - v[26] - v[57] - dmEthanol__3dt;
    v[59] = yEthanol__5 * V__4;
    v[60] = (1 - xFWater) * feed;
    v[35] = v[36] * v[35];
    res[12] = v[26] + v[59] + v[60] - v[35] - v[58] - dmEthanol__4dt;
    v[61] = yEthanol__6 * V__5;
    v[43] = v[44] * v[43];
    res[13] = v[35] + v[61] - v[59] - v[43] - dmEthanol__5dt;
    v[62] = yEthanol__7 * V__6;
    v[51] = v[52] * v[51];
    res[14] = v[43] + v[62] - v[51] - v[61] - dmEthanol__6dt;
    v[63] = 1 - v[53];
    res[15] = v[51] - v[63] * Frectifier - v[62] - dmEthanol__7dt;
    v[64] = 0.018015283300000001 * mWater__0;
    v[65] = v[64] + 0.046068440000000002 * mEthanol__0;
    v[64] = v[64] / v[65];
    res[16] = (V__0 * (yWater__1 * 0.00052052999999999995 * pow(1 - T__1 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__1) / 647 + ((0.25795000000000001 * T__1) / 647 * T__1) / 647) + yEthanol__1 * 50430 * pow(1 - T__1 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__1) / 514)) + 0.018015283300000001 * v[0] * (1851.9275797344801 * T__1 + 3881998.0699387612 / tanh(2610.5 / T__1) - 577255.64604360121 * tanh(1169 / T__1) - (1851.9275797344801 * T__1 + 3881998.0699387612 / tanh(2610.5 / T__1) - 577255.64604360121 * tanh(1169 / T__1))) + 0.046068440000000002 * v[54] * (1067.9762544596692 * T__1 + 5261440.5002643894 / tanh(1662.8 / T__1) - 1517900.9751578306 * tanh(744.70000000000005 / T__1) - (1067.9762544596692 * T__1 + 5261440.5002643894 / tanh(1662.8 / T__1) - 1517900.9751578306 * tanh(744.70000000000005 / T__1))) + 0 - 1000 * Qc) / (v[65] * (v[64] * (15340.863387921299 + -116.01815887069618 * T__0 + 0.45100595226276569 * T__0 * T__0 + -0.00078355692580199391 * T__0 * T__0 * T__0 + 5.2011949209813426e-07 * T__0 * T__0 * T__0 * T__0) + (1 - v[64]) * (2227.989486945944 + -3.0309252928903172 * T__0 + -0.00065860706375123624 * T__0 * T__0 + 4.4251552689867506e-05 * T__0 * T__0 * T__0))) - dT__0dt;
    v[64] = T__0 * T__0;
    v[65] = T__1 * T__1;
    res[17] = (0.018015283300000001 * v[3] * (15340.863387921299 * (T__0 - T__1) + -58.009079435348092 * (T__0 * T__0 - T__1 * T__1) + 0.1503353174209219 * (T__0 * T__0 * T__0 - T__1 * T__1 * T__1) + -0.00019588923145049848 * (T__0 * T__0 * T__0 * T__0 - T__1 * T__1 * T__1 * T__1) + 1.0402389841962685e-07 * (v[64] * v[64] * T__0 - v[65] * v[65] * T__1)) + 0.046068440000000002 * v[2] * (2227.989486945944 * (T__0 - T__1) + -1.5154626464451586 * (T__0 * T__0 - T__1 * T__1) + -0.00021953568791707875 * (T__0 * T__0 * T__0 - T__1 * T__1 * T__1) + 1.1062888172466876e-05 * (T__0 * T__0 * T__0 * T__0 - T__1 * T__1 * T__1 * T__1)) + V__1 * (yWater__2 * 0.00052052999999999995 * pow(1 - T__2 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__2) / 647 + ((0.25795000000000001 * T__2) / 647 * T__2) / 647) + yEthanol__2 * 50430 * pow(1 - T__2 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__2) / 514)) + 0.018015283300000001 * v[4] * (1851.9275797344801 * T__2 + 3881998.0699387612 / tanh(2610.5 / T__2) - 577255.64604360121 * tanh(1169 / T__2) - (1851.9275797344801 * T__2 + 3881998.0699387612 / tanh(2610.5 / T__2) - 577255.64604360121 * tanh(1169 / T__2))) + 0.046068440000000002 * v[56] * (1067.9762544596692 * T__2 + 5261440.5002643894 / tanh(1662.8 / T__2) - 1517900.9751578306 * tanh(744.70000000000005 / T__2) - (1067.9762544596692 * T__2 + 5261440.5002643894 / tanh(1662.8 / T__2) - 1517900.9751578306 * tanh(744.70000000000005 / T__2))) - V__0 * (yWater__1 * 0.00052052999999999995 * pow(1 - T__1 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__1) / 647 + ((0.25795000000000001 * T__1) / 647 * T__1) / 647) + yEthanol__1 * 50430 * pow(1 - T__1 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__1) / 514))) / (v[7] * (v[6] * (15340.863387921299 + -116.01815887069618 * T__1 + 0.45100595226276569 * T__1 * T__1 + -0.00078355692580199391 * T__1 * T__1 * T__1 + 5.2011949209813426e-07 * T__1 * T__1 * T__1 * T__1) + v[8] * (2227.989486945944 + -3.0309252928903172 * T__1 + -0.00065860706375123624 * T__1 * T__1 + 4.4251552689867506e-05 * T__1 * T__1 * T__1))) - dT__1dt;
    v[65] = T__1 * T__1;
    v[64] = T__2 * T__2;
    res[18] = (V__2 * (yWater__3 * 0.00052052999999999995 * pow(1 - T__3 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__3) / 647 + ((0.25795000000000001 * T__3) / 647 * T__3) / 647) + yEthanol__3 * 50430 * pow(1 - T__3 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__3) / 514)) + 0.018015283300000001 * v[12] * (1851.9275797344801 * T__3 + 3881998.0699387612 / tanh(2610.5 / T__3) - 577255.64604360121 * tanh(1169 / T__3) - (1851.9275797344801 * T__3 + 3881998.0699387612 / tanh(2610.5 / T__3) - 577255.64604360121 * tanh(1169 / T__3))) + 0.046068440000000002 * v[57] * (1067.9762544596692 * T__3 + 5261440.5002643894 / tanh(1662.8 / T__3) - 1517900.9751578306 * tanh(744.70000000000005 / T__3) - (1067.9762544596692 * T__3 + 5261440.5002643894 / tanh(1662.8 / T__3) - 1517900.9751578306 * tanh(744.70000000000005 / T__3))) + 0.018015283300000001 * v[9] * (15340.863387921299 * (T__1 - T__2) + -58.009079435348092 * (T__1 * T__1 - T__2 * T__2) + 0.1503353174209219 * (T__1 * T__1 * T__1 - T__2 * T__2 * T__2) + -0.00019588923145049848 * (T__1 * T__1 * T__1 * T__1 - T__2 * T__2 * T__2 * T__2) + 1.0402389841962685e-07 * (v[65] * v[65] * T__1 - v[64] * v[64] * T__2)) + 0.046068440000000002 * v[10] * (2227.989486945944 * (T__1 - T__2) + -1.5154626464451586 * (T__1 * T__1 - T__2 * T__2) + -0.00021953568791707875 * (T__1 * T__1 * T__1 - T__2 * T__2 * T__2) + 1.1062888172466876e-05 * (T__1 * T__1 * T__1 * T__1 - T__2 * T__2 * T__2 * T__2)) - V__1 * (yWater__2 * 0.00052052999999999995 * pow(1 - T__2 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__2) / 647 + ((0.25795000000000001 * T__2) / 647 * T__2) / 647) + yEthanol__2 * 50430 * pow(1 - T__2 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__2) / 514))) / (v[15] * (v[14] * (15340.863387921299 + -116.01815887069618 * T__2 + 0.45100595226276569 * T__2 * T__2 + -0.00078355692580199391 * T__2 * T__2 * T__2 + 5.2011949209813426e-07 * T__2 * T__2 * T__2 * T__2) + v[16] * (2227.989486945944 + -3.0309252928903172 * T__2 + -0.00065860706375123624 * T__2 * T__2 + 4.4251552689867506e-05 * T__2 * T__2 * T__2))) - dT__2dt;
    v[64] = T__2 * T__2;
    v[65] = T__3 * T__3;
    res[19] = (0.018015283300000001 * v[17] * (15340.863387921299 * (T__2 - T__3) + -58.009079435348092 * (T__2 * T__2 - T__3 * T__3) + 0.1503353174209219 * (T__2 * T__2 * T__2 - T__3 * T__3 * T__3) + -0.00019588923145049848 * (T__2 * T__2 * T__2 * T__2 - T__3 * T__3 * T__3 * T__3) + 1.0402389841962685e-07 * (v[64] * v[64] * T__2 - v[65] * v[65] * T__3)) + 0.046068440000000002 * v[18] * (2227.989486945944 * (T__2 - T__3) + -1.5154626464451586 * (T__2 * T__2 - T__3 * T__3) + -0.00021953568791707875 * (T__2 * T__2 * T__2 - T__3 * T__3 * T__3) + 1.1062888172466876e-05 * (T__2 * T__2 * T__2 * T__2 - T__3 * T__3 * T__3 * T__3)) + V__3 * (yWater__4 * 0.00052052999999999995 * pow(1 - T__4 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__4) / 647 + ((0.25795000000000001 * T__4) / 647 * T__4) / 647) + yEthanol__4 * 50430 * pow(1 - T__4 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__4) / 514)) + 0.018015283300000001 * v[20] * (1851.9275797344801 * T__4 + 3881998.0699387612 / tanh(2610.5 / T__4) - 577255.64604360121 * tanh(1169 / T__4) - (1851.9275797344801 * T__4 + 3881998.0699387612 / tanh(2610.5 / T__4) - 577255.64604360121 * tanh(1169 / T__4))) + 0.046068440000000002 * v[58] * (1067.9762544596692 * T__4 + 5261440.5002643894 / tanh(1662.8 / T__4) - 1517900.9751578306 * tanh(744.70000000000005 / T__4) - (1067.9762544596692 * T__4 + 5261440.5002643894 / tanh(1662.8 / T__4) - 1517900.9751578306 * tanh(744.70000000000005 / T__4))) - V__2 * (yWater__3 * 0.00052052999999999995 * pow(1 - T__3 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__3) / 647 + ((0.25795000000000001 * T__3) / 647 * T__3) / 647) + yEthanol__3 * 50430 * pow(1 - T__3 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__3) / 514))) / (v[23] * (v[22] * (15340.863387921299 + -116.01815887069618 * T__3 + 0.45100595226276569 * T__3 * T__3 + -0.00078355692580199391 * T__3 * T__3 * T__3 + 5.2011949209813426e-07 * T__3 * T__3 * T__3 * T__3) + v[24] * (2227.989486945944 + -3.0309252928903172 * T__3 + -0.00065860706375123624 * T__3 * T__3 + 4.4251552689867506e-05 * T__3 * T__3 * T__3))) - dT__3dt;
    v[65] = T__3 * T__3;
    v[64] = T__4 * T__4;
    v[58] = Tfeed * Tfeed;
    v[18] = T__4 * T__4;
    res[20] = (0.018015283300000001 * v[25] * (15340.863387921299 * (T__3 - T__4) + -58.009079435348092 * (T__3 * T__3 - T__4 * T__4) + 0.1503353174209219 * (T__3 * T__3 * T__3 - T__4 * T__4 * T__4) + -0.00019588923145049848 * (T__3 * T__3 * T__3 * T__3 - T__4 * T__4 * T__4 * T__4) + 1.0402389841962685e-07 * (v[65] * v[65] * T__3 - v[64] * v[64] * T__4)) + 0.046068440000000002 * v[26] * (2227.989486945944 * (T__3 - T__4) + -1.5154626464451586 * (T__3 * T__3 - T__4 * T__4) + -0.00021953568791707875 * (T__3 * T__3 * T__3 - T__4 * T__4 * T__4) + 1.1062888172466876e-05 * (T__3 * T__3 * T__3 * T__3 - T__4 * T__4 * T__4 * T__4)) + V__4 * (yWater__5 * 0.00052052999999999995 * pow(1 - T__5 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__5) / 647 + ((0.25795000000000001 * T__5) / 647 * T__5) / 647) + yEthanol__5 * 50430 * pow(1 - T__5 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__5) / 514)) + 0.018015283300000001 * v[28] * (1851.9275797344801 * T__5 + 3881998.0699387612 / tanh(2610.5 / T__5) - 577255.64604360121 * tanh(1169 / T__5) - (1851.9275797344801 * T__5 + 3881998.0699387612 / tanh(2610.5 / T__5) - 577255.64604360121 * tanh(1169 / T__5))) + 0.046068440000000002 * v[59] * (1067.9762544596692 * T__5 + 5261440.5002643894 / tanh(1662.8 / T__5) - 1517900.9751578306 * tanh(744.70000000000005 / T__5) - (1067.9762544596692 * T__5 + 5261440.5002643894 / tanh(1662.8 / T__5) - 1517900.9751578306 * tanh(744.70000000000005 / T__5))) + 0.018015283300000001 * v[29] * (15340.863387921299 * (Tfeed - T__4) + -58.009079435348092 * (Tfeed * Tfeed - T__4 * T__4) + 0.1503353174209219 * (Tfeed * Tfeed * Tfeed - T__4 * T__4 * T__4) + -0.00019588923145049848 * (Tfeed * Tfeed * Tfeed * Tfeed - T__4 * T__4 * T__4 * T__4) + 1.0402389841962685e-07 * (v[58] * v[58] * Tfeed - v[18] * v[18] * T__4)) + 0.046068440000000002 * v[60] * (2227.989486945944 * (Tfeed - T__4) + -1.5154626464451586 * (Tfeed * Tfeed - T__4 * T__4) + -0.00021953568791707875 * (Tfeed * Tfeed * Tfeed - T__4 * T__4 * T__4) + 1.1062888172466876e-05 * (Tfeed * Tfeed * Tfeed * Tfeed - T__4 * T__4 * T__4 * T__4)) - V__3 * (yWater__4 * 0.00052052999999999995 * pow(1 - T__4 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__4) / 647 + ((0.25795000000000001 * T__4) / 647 * T__4) / 647) + yEthanol__4 * 50430 * pow(1 - T__4 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__4) / 514))) / (v[32] * (v[31] * (15340.863387921299 + -116.01815887069618 * T__4 + 0.45100595226276569 * T__4 * T__4 + -0.00078355692580199391 * T__4 * T__4 * T__4 + 5.2011949209813426e-07 * T__4 * T__4 * T__4 * T__4) + v[33] * (2227.989486945944 + -3.0309252928903172 * T__4 + -0.00065860706375123624 * T__4 * T__4 + 4.4251552689867506e-05 * T__4 * T__4 * T__4))) - dT__4dt;
    v[18] = T__4 * T__4;
    v[58] = T__5 * T__5;
    res[21] = (0.018015283300000001 * v[34] * (15340.863387921299 * (T__4 - T__5) + -58.009079435348092 * (T__4 * T__4 - T__5 * T__5) + 0.1503353174209219 * (T__4 * T__4 * T__4 - T__5 * T__5 * T__5) + -0.00019588923145049848 * (T__4 * T__4 * T__4 * T__4 - T__5 * T__5 * T__5 * T__5) + 1.0402389841962685e-07 * (v[18] * v[18] * T__4 - v[58] * v[58] * T__5)) + 0.046068440000000002 * v[35] * (2227.989486945944 * (T__4 - T__5) + -1.5154626464451586 * (T__4 * T__4 - T__5 * T__5) + -0.00021953568791707875 * (T__4 * T__4 * T__4 - T__5 * T__5 * T__5) + 1.1062888172466876e-05 * (T__4 * T__4 * T__4 * T__4 - T__5 * T__5 * T__5 * T__5)) + V__5 * (yWater__6 * 0.00052052999999999995 * pow(1 - T__6 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__6) / 647 + ((0.25795000000000001 * T__6) / 647 * T__6) / 647) + yEthanol__6 * 50430 * pow(1 - T__6 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__6) / 514)) + 0.018015283300000001 * v[37] * (1851.9275797344801 * T__6 + 3881998.0699387612 / tanh(2610.5 / T__6) - 577255.64604360121 * tanh(1169 / T__6) - (1851.9275797344801 * T__6 + 3881998.0699387612 / tanh(2610.5 / T__6) - 577255.64604360121 * tanh(1169 / T__6))) + 0.046068440000000002 * v[61] * (1067.9762544596692 * T__6 + 5261440.5002643894 / tanh(1662.8 / T__6) - 1517900.9751578306 * tanh(744.70000000000005 / T__6) - (1067.9762544596692 * T__6 + 5261440.5002643894 / tanh(1662.8 / T__6) - 1517900.9751578306 * tanh(744.70000000000005 / T__6))) - V__4 * (yWater__5 * 0.00052052999999999995 * pow(1 - T__5 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__5) / 647 + ((0.25795000000000001 * T__5) / 647 * T__5) / 647) + yEthanol__5 * 50430 * pow(1 - T__5 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__5) / 514))) / (v[40] * (v[39] * (15340.863387921299 + -116.01815887069618 * T__5 + 0.45100595226276569 * T__5 * T__5 + -0.00078355692580199391 * T__5 * T__5 * T__5 + 5.2011949209813426e-07 * T__5 * T__5 * T__5 * T__5) + v[41] * (2227.989486945944 + -3.0309252928903172 * T__5 + -0.00065860706375123624 * T__5 * T__5 + 4.4251552689867506e-05 * T__5 * T__5 * T__5))) - dT__5dt;
    v[58] = T__5 * T__5;
    v[18] = T__6 * T__6;
    res[22] = (0.018015283300000001 * v[42] * (15340.863387921299 * (T__5 - T__6) + -58.009079435348092 * (T__5 * T__5 - T__6 * T__6) + 0.1503353174209219 * (T__5 * T__5 * T__5 - T__6 * T__6 * T__6) + -0.00019588923145049848 * (T__5 * T__5 * T__5 * T__5 - T__6 * T__6 * T__6 * T__6) + 1.0402389841962685e-07 * (v[58] * v[58] * T__5 - v[18] * v[18] * T__6)) + 0.046068440000000002 * v[43] * (2227.989486945944 * (T__5 - T__6) + -1.5154626464451586 * (T__5 * T__5 - T__6 * T__6) + -0.00021953568791707875 * (T__5 * T__5 * T__5 - T__6 * T__6 * T__6) + 1.1062888172466876e-05 * (T__5 * T__5 * T__5 * T__5 - T__6 * T__6 * T__6 * T__6)) + V__6 * (yWater__7 * 0.00052052999999999995 * pow(1 - T__7 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__7) / 647 + ((0.25795000000000001 * T__7) / 647 * T__7) / 647) + yEthanol__7 * 50430 * pow(1 - T__7 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__7) / 514)) + 0.018015283300000001 * v[45] * (1851.9275797344801 * T__7 + 3881998.0699387612 / tanh(2610.5 / T__7) - 577255.64604360121 * tanh(1169 / T__7) - (1851.9275797344801 * T__7 + 3881998.0699387612 / tanh(2610.5 / T__7) - 577255.64604360121 * tanh(1169 / T__7))) + 0.046068440000000002 * v[62] * (1067.9762544596692 * T__7 + 5261440.5002643894 / tanh(1662.8 / T__7) - 1517900.9751578306 * tanh(744.70000000000005 / T__7) - (1067.9762544596692 * T__7 + 5261440.5002643894 / tanh(1662.8 / T__7) - 1517900.9751578306 * tanh(744.70000000000005 / T__7))) - V__5 * (yWater__6 * 0.00052052999999999995 * pow(1 - T__6 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__6) / 647 + ((0.25795000000000001 * T__6) / 647 * T__6) / 647) + yEthanol__6 * 50430 * pow(1 - T__6 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__6) / 514))) / (v[48] * (v[47] * (15340.863387921299 + -116.01815887069618 * T__6 + 0.45100595226276569 * T__6 * T__6 + -0.00078355692580199391 * T__6 * T__6 * T__6 + 5.2011949209813426e-07 * T__6 * T__6 * T__6 * T__6) + v[49] * (2227.989486945944 + -3.0309252928903172 * T__6 + -0.00065860706375123624 * T__6 * T__6 + 4.4251552689867506e-05 * T__6 * T__6 * T__6))) - dT__6dt;
    v[18] = T__6 * T__6;
    v[58] = T__7 * T__7;
    v[62] = 0.018015283300000001 * mWater__7;
    v[43] = v[62] + 0.046068440000000002 * mEthanol__7;
    v[62] = v[62] / v[43];
    res[23] = (0.018015283300000001 * v[50] * (15340.863387921299 * (T__6 - T__7) + -58.009079435348092 * (T__6 * T__6 - T__7 * T__7) + 0.1503353174209219 * (T__6 * T__6 * T__6 - T__7 * T__7 * T__7) + -0.00019588923145049848 * (T__6 * T__6 * T__6 * T__6 - T__7 * T__7 * T__7 * T__7) + 1.0402389841962685e-07 * (v[18] * v[18] * T__6 - v[58] * v[58] * T__7)) + 0.046068440000000002 * v[51] * (2227.989486945944 * (T__6 - T__7) + -1.5154626464451586 * (T__6 * T__6 - T__7 * T__7) + -0.00021953568791707875 * (T__6 * T__6 * T__6 - T__7 * T__7 * T__7) + 1.1062888172466876e-05 * (T__6 * T__6 * T__6 * T__6 - T__7 * T__7 * T__7 * T__7)) - V__6 * (yWater__7 * 0.00052052999999999995 * pow(1 - T__7 / 647, 0.31990000000000002 + (-0.21199999999999999 * T__7) / 647 + ((0.25795000000000001 * T__7) / 647 * T__7) / 647) + yEthanol__7 * 50430 * pow(1 - T__7 / 514, 0.49890000000000001) * exp((0.44750000000000001 * T__7) / 514)) + 1000 * Qsteam) / (v[43] * (v[62] * (15340.863387921299 + -116.01815887069618 * T__7 + 0.45100595226276569 * T__7 * T__7 + -0.00078355692580199391 * T__7 * T__7 * T__7 + 5.2011949209813426e-07 * T__7 * T__7 * T__7 * T__7) + (1 - v[62]) * (2227.989486945944 + -3.0309252928903172 * T__7 + -0.00065860706375123624 * T__7 * T__7 + 4.4251552689867506e-05 * T__7 * T__7 * T__7))) - dT__7dt;
    v[62] = 101325 * P;
    res[24] = yWater__0 - v[1] * (100000 * pow(10, 4.6543000000000001 - 1435.2639999999999 / (-64.847999999999999 + T__0))) / v[62];
    res[25] = yWater__1 - v[5] * (100000 * pow(10, 4.6543000000000001 - 1435.2639999999999 / (-64.847999999999999 + T__1))) / v[62];
    res[26] = yWater__2 - v[13] * (100000 * pow(10, 4.6543000000000001 - 1435.2639999999999 / (-64.847999999999999 + T__2))) / v[62];
    res[27] = yWater__3 - v[21] * (100000 * pow(10, 4.6543000000000001 - 1435.2639999999999 / (-64.847999999999999 + T__3))) / v[62];
    res[28] = yWater__4 - v[30] * (100000 * pow(10, 4.6543000000000001 - 1435.2639999999999 / (-64.847999999999999 + T__4))) / v[62];
    res[29] = yWater__5 - v[38] * (100000 * pow(10, 4.6543000000000001 - 1435.2639999999999 / (-64.847999999999999 + T__5))) / v[62];
    res[30] = yWater__6 - v[46] * (100000 * pow(10, 4.6543000000000001 - 1435.2639999999999 / (-64.847999999999999 + T__6))) / v[62];
    res[31] = yWater__7 - v[53] * (100000 * pow(10, 4.6543000000000001 - 1435.2639999999999 / (-64.847999999999999 + T__7))) / v[62];
    res[32] = yEthanol__0 - v[55] * (100000 * pow(10, 4.9253099999999996 - 1432.5260000000001 / (-61.819000000000003 + T__0))) / v[62];
    res[33] = yEthanol__1 - v[11] * (100000 * pow(10, 4.9253099999999996 - 1432.5260000000001 / (-61.819000000000003 + T__1))) / v[62];
    res[34] = yEthanol__2 - v[19] * (100000 * pow(10, 4.9253099999999996 - 1432.5260000000001 / (-61.819000000000003 + T__2))) / v[62];
    res[35] = yEthanol__3 - v[27] * (100000 * pow(10, 4.9253099999999996 - 1432.5260000000001 / (-61.819000000000003 + T__3))) / v[62];
    res[36] = yEthanol__4 - v[36] * (100000 * pow(10, 4.9253099999999996 - 1432.5260000000001 / (-61.819000000000003 + T__4))) / v[62];
    res[37] = yEthanol__5 - v[44] * (100000 * pow(10, 4.9253099999999996 - 1432.5260000000001 / (-61.819000000000003 + T__5))) / v[62];
    res[38] = yEthanol__6 - v[52] * (100000 * pow(10, 4.9253099999999996 - 1432.5260000000001 / (-61.819000000000003 + T__6))) / v[62];
    res[39] = yEthanol__7 - v[63] * (100000 * pow(10, 4.9253099999999996 - 1432.5260000000001 / (-61.819000000000003 + T__7))) / v[62];
    res[40] = 1 - yWater__1 - yEthanol__1;
    res[41] = 1 - yWater__2 - yEthanol__2;
    res[42] = 1 - yWater__3 - yEthanol__3;
    res[43] = 1 - yWater__4 - yEthanol__4;
    res[44] = 1 - yWater__5 - yEthanol__5;
    res[45] = 1 - yWater__6 - yEthanol__6;
    res[46] = 1 - yWater__7 - yEthanol__7;
    res[47] = 1 - yWater__0 - yEthanol__0;

    // create f: U -> res and vectors used for derivative calculations
    return new ADFun<Base > (U, res);
}

} // END cg namespace
} // END CppAD namespace

#endif
