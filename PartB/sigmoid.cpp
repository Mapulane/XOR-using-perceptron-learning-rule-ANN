#include<fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include<cmath>


using namespace std;

void   sigmoid(float outputExpected,vector<float> input,vector<float> bH,vector<vector<float>> weightsH, float bY, vector<float> weightsY){

  cout<<"**********************************************"<<endl;
  cout<<"   Running the  Feed-Forward Neural Networks  "<<endl;
  cout<<"**********************************************"<<endl;

    float outputANN =0;
    float outputH1 =0;
    float outputH2 =0;
    float sumNode1 =0;
    float sumNode2 =0;

    ofstream file;
    file.open("Output2.txt");

    file<< " ANN inputs"<<endl;
    cout<< "ANN inputs"<<endl;
    for (int l = 0; l < input.size(); ++l) {

        file<<input[l]<<endl;
        cout <<" " <<input[l]<<endl;
     }

/*** FIRST ANN LAYER ***/

    // calculating the weight * input for the first ANN layer
    for(int i =0; i<input.size(); ++i){
      sumNode1 += weightsH[i][0]*input[i];
      sumNode2 += weightsH[i][1]*input[i];
    }


    //add the bais value
    sumNode1 += bH[0];
    sumNode2 +=bH[1];

    //calculate the sigmoid value
     outputH1 = 1/(1 + exp(-1*sumNode1));
     outputH2 = 1/(1 + exp(-1*sumNode2));

     file<<endl<<" * Hidden Layer Neuron value* "<<endl;
     file<<outputH1<<endl<<outputH2<<endl;

     cout<<endl<<" * Hidden Layer Neuron value* "<<endl;
     cout<<outputH1<<endl<<outputH2<<endl;


/*** Second ANN LAYER ***/
  // calculating the weight * input for the second ANN layer

    float sumNodeY = weightsY[0]*outputH1 + weightsY[1]*outputH2;

    //add the bais value
    sumNodeY += bY;

    //calculate the sigmoid value
    outputANN = 1/(1 + exp(-1*sumNodeY));

     file<<endl<<" * Output Neuron value* "<<endl;
     file<<outputANN<<endl;

     cout<<endl<<" * Output Neuron value* "<<endl;
     cout<<outputANN<<endl;

 /*** Mean Squared Error***/
 float base =outputExpected - outputANN;
 float MSE  = pow(base,2);

 file<<endl<<" * Mean Squared Error * "<<endl;
 file<<MSE<<endl;

 cout<<endl<<" * Mean Squared Error * "<<endl;
 cout<<MSE<<endl;


}

/*****          main function      ********
*****                              *******/

int main(int argc, char const *argv[]) {

  float outputExpected =0.36;
  vector<float> input ={1.30, 2.70, 0.80};
  vector<float> bH ={0.1,-0.3};
  vector<vector<float>> weightsH = {{0.1, -0.4},{0.2, 1.0},{0.5 ,-0.6}};
  float bY = -0.3;
  vector<float> weightsY = {0.8, 1.0};

  sigmoid(outputExpected, input , bH, weightsH, bY, weightsY );

  return 0;
}
