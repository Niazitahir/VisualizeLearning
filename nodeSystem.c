#include <stdlib.h>
#include <stdio.h>
#include <math.h>



const int numLayers = 3;
const int numInputs = 6;
const int numOutputs = 2;

int numNeurons[numLayers];



typedef struct neuron{
    struct neuron *next;
    int *weights;
    int index;
}neuron;

typedef struct layer{
    int index;
    int bias; //this is the value the layer stores
    struct layer *next; //this is the layer the current layer points to. this is how the layers link
    struct neuron *topNeuron;
}layer;


typedef struct list{
    struct node* head;
}list;

neuron *createNeuron(int ind){
    neuron *newNeuron = malloc(sizeof(neuron));
    newNeuron->next = NULL;
    newNeuron->weights = NULL;
    newNeuron->index = ind;
}

void setWeights(int *arr, int *values){
    while(arr != NULL){
        *arr = *values;
        values++;
        arr++;
    }
}

int* createRandWeights(int length){
    srand(time(NULL));
    int *temp;
    for(int i = 0; i<length; i++){
        *temp = rand() % 10 + 1;
        temp++;
    }

}


layer *createlayer(int val, int ind){
    layer *newlayer = malloc(sizeof(layer));
    newlayer->bias = val;
    newlayer->index = ind;
    newlayer->next = NULL;
    return newlayer;
}


int randomBias(){
    srand(time(NULL));
    return rand();
}


int main(){
    for (int i = 0; i<numLayers;i++){
        numNeurons[i] = 3;
    }
    layer *newNet = createLayer(-69);
    for (int i = 0; i<numLayers; i++){
        layer *temp = createlayer(randomBias(), i);
        newNet->next = temp;
        temp->topNeuron = createNeuron(0);
        neuron *top = temp->topNeuron;
        for(int j = 1; j<numNeurons[i]; j++){
            neuron *tempNeuron = createNeuron(j);
            top->next = tempNeuron;
            top = top->next;
        }
    }
    

}

