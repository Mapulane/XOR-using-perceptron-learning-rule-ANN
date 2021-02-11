#include<fstream>
#include <iostream>
#include <vector>


using namespace std;

vector<float> PerceptronLearning(vector<vector<float>> input, vector<float> outputExpected, vector<float> weight, float Threshold, float learningRate ){

    float sum;
    int iter = 0;
    bool done = false;

    float outputTarget =0;
    float outputNeuron =0;
    vector<float> result;

    while( not done){

      //computing the difference in weights
    for(int i=0; i<outputExpected.size(); ++i){
        outputTarget = outputExpected[i];

        sum =0;
        for (int j = 0; j < input[0].size(); ++j) {
          sum = sum + input[i][j]*weight[j];
        }

        //calculating the neuron output
        if(sum < Threshold){
          outputNeuron =0;
          result.push_back(outputNeuron);
        }
        else{
          outputNeuron = 1;
          result.push_back(outputNeuron);
        }

        //check if there is a different in target output and neuron output
        if(outputTarget != outputNeuron){
          for(int k=0; k<input[0].size(); k++){
            weight[k]= weight[k] + (learningRate*(outputTarget - outputNeuron)*input[i][k]);
          }
        }
      }

      if(result == outputExpected ){
        cout<< "Model trained correctly"<<endl;
        done = true;
	    }
      else if(iter == 20){
          done= true;
          cout<< "Model incorrectly trained, iteration limit reached"<<endl;
      }
      cout<<"neuron results Vs  expected results"<<endl;
      for (int i = 0; i < result.size(); ++i) {
          cout <<" "<< result[i]<< " "<< outputExpected[i] <<endl;;
       }

     iter +=1;
    }
    return result;

}


int main(int argc, char const *argv[]) {

  float Rate =0.5;
  vector<vector<float>> X1X2 = {{0,0},{0,1},{1,0},{1,1}};

  ofstream file;
  file.open("Output.txt");

  file<< "Inputs X1 and X2 "<<endl;
  cout<< "Inputs X1 and X2 "<<endl;
  for (int l = 0; l < X1X2.size(); ++l) {

      file<<X1X2[l][0]<< " "<< X1X2[l][1]<<endl;
      cout <<" " <<X1X2[l][0]<< " "<< X1X2[l][1] <<endl;;
   }

  // ********* OR training*********

      cout<<endl<<" ***OR PERCEPTRON lEARNING*** "<<endl;
      float Threshold = 0.5;
      std::vector<float> weight = {1,1};
      vector<float> output = {0,1,1,1};

      vector<float> ORoutput = PerceptronLearning(X1X2, output, weight, Threshold, Rate);


  // ********* NAND training*********
    cout<<endl<<" ***NAND PERCEPTRON lEARNING*** "<<endl;

    Rate =0.5;
    Threshold = -1.5;
    weight = {-1,-1};
    vector<float> output1 = {1,1,1,0};

    vector<float> NANDoutput = PerceptronLearning(X1X2, output1, weight, Threshold, Rate);


    // ******** AND training**************
    cout<<endl<<" ***AND PERCEPTRON lEARNING*** "<<endl;
    Rate =0.5;
    Threshold = 1.5;
    weight = {1,1};

    //creating inputs vector for AND perceptron Learning from OR and AND outputs
    vector<vector<float>> OrNand(ORoutput.size());
    for(int i=0; i<ORoutput.size(); ++i){
        OrNand[i] = vector<float>(2);
        OrNand[i][0]=ORoutput[i];
        OrNand[i][1]=NANDoutput[i];
    }
    vector<float> output2 = {0,1,1,0};

    vector<float> ANDoutput = PerceptronLearning(OrNand, output2, weight, Threshold, Rate);

    file<<endl<<" ***OR PERCEPTRON lEARNING*** "<<endl;
    for(int s=0; s<ORoutput.size(); ++s){
        file<<ORoutput[s]<<endl;
    }

    file<<endl<<" ***NAND PERCEPTRON lEARNING*** "<<endl;
    for(int s=0; s<NANDoutput.size(); ++s){
        file<<NANDoutput[s]<<endl;
    }

    file<<endl<<" ***AND PERCEPTRON lEARNING*** "<<endl;
    for(int s=0; s<ANDoutput.size(); ++s){
        file<<ANDoutput[s]<<endl;
    }
  return 0;
}
