#include <iostream>
#include <vector>

using namespace std;

float max_substrate_sum(const vector<float>& inputData) {
    int inputSize = inputData.size();
    float final_max = inputData[0];

    for (int i = 0; i < inputSize; i++) {
        float sum = inputData[i];
        final_max = std::max(final_max, sum);
        for (int j = (i + 1); j < inputSize; j++) {
            sum += inputData[j];
            final_max = std::max(final_max, sum);
        }
    }
    return final_max;
}

int main(){

    vector<float> input1 = {1, -2, 3, -4, 5};
    float output1 = max_substrate_sum(input1);
    cout << "Output " << output1 <<  endl;
  
  return 0;
}
