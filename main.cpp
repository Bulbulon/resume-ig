#include <iostream>
#include <random>
#include <ctime>
#include <map>
#include <vector>
#include<algorithm>


using namespace std;

enum Color {B = 0, O = 1, G = 2,  R = 3, W = 4, Y = 5};
enum Rotation{UR = 0, UL = 1, DR = 2, DL = 3, RF = 4, RB = 5, LF = 6, LB = 7, FR = 9, FL = 10, BR = 11, BL = 12};

class rubix
{
    public:
        Color*** cube;
    rubix()
    {
        int face = 6; int dimx = 3; int dimy = 3;
        Color temp[6] = {B,O,G,R,W,Y};
        Color*** array;
        array = new Color**[face];
        for(int f = 0; f < face; ++f)
        {
            array[f] = new Color*[dimx];
            for(int x = 0; x < dimx; ++x)
            {
                array[f][x] = new Color[dimy];
                for(int y = 0; y < dimy; ++y)
                { 
                    array[f][x][y] = temp[f];
                }
            }
        }
        cube = array;
    }

void rotate(string r)
{
    //up right
    if(r == "UR")
    {
        Color* temp = cube[0][0];
        cube[0][0] = cube[3][0];
        cube[3][0] = cube[2][0];
        cube[2][0] = cube[1][0];
        cube[1][0] = temp;
        rotateFace(4, "R");
    }
    //up left
    else if(r == "UL")
    {
        Color* temp = cube[0][0];
        cube[0][0] = cube[1][0];
        cube[1][0] = cube[2][0];
        cube[2][0] = cube[3][0];
        cube[3][0] = temp;
        rotateFace(4, "L");
    }
    //down right
    else  if(r == "DR")
    {
        Color* temp = cube[0][2];
        cube[0][2] = cube[3][2];
        cube[3][2] = cube[2][2];
        cube[2][2] = cube[1][2];
        cube[1][2] = temp;
        rotateFace(5, "R");
    }
    //downleft
    else if(r == "DL")
    {
        Color* temp = cube[0][2];
        cube[0][2] = cube[1][2];
        cube[1][2] = cube[2][2];
        cube[2][2] = cube[3][2];
        cube[3][2] = temp;
        rotateFace(5, "L");
    }
    /*
    //middle right
    else  if(r == "MR")
    {
        Color* temp = cube[0][1];
        cube[0][1] = cube[3][1];
        cube[3][1] = cube[2][1];
        cube[2][1] = cube[1][1];
        cube[1][1] = temp;
    }
    //middle left
    else if(r == "ML")
    {
        Color* temp = cube[0][1];
        cube[0][1] = cube[1][1];
        cube[1][1] = cube[2][1];
        cube[2][1] = cube[3][1];
        cube[3][1] = temp;
    }*/
    //right forward
    else if(r == "RF")
    {
        for (int i = 0; i < 3; i++)
        {
            Color temp = cube[0][i][2];
            cube[0][i][2] = cube[5][i][2];
            cube[5][i][2] = cube[2][i][2];
            cube[2][i][2] = cube[4][i][2];
            cube[4][i][2] = temp;  
        }
        rotateFace(2, "R");
    }
    //right backwars
    else if(r == "RB")
    {
        for (int i = 0; i < 3; i++)
        {
            Color temp = cube[0][i][2];
            cube[0][i][2] = cube[4][i][2];
            cube[4][i][2] = cube[2][i][2];
            cube[2][i][2] = cube[5][i][2];
            cube[5][i][2] = temp;  
        }
        rotateFace(2, "R");
        
    }
    //left forward
    else if(r == "LF")
    {
        for (int i = 0; i < 3; i++)
        {
            Color temp = cube[0][i][0];
            cube[0][i][0] = cube[5][i][0];
            cube[5][i][0] = cube[2][i][0];
            cube[2][i][0] = cube[4][i][0];
            cube[4][i][0] = temp;  
        }
        rotateFace(3, "L");
        
    }
    //left backward
    else if(r == "LB")
    {
        for (int i = 0; i < 3; i++)
        {
            Color temp = cube[0][i][0];
            cube[0][i][0] = cube[4][i][0];
            cube[4][i][0] = cube[2][i][0];
            cube[2][i][0] = cube[5][i][0];
            cube[5][i][0] = temp;  
        }
        rotateFace(3, "R");
        
    }
    //front right
    else if (r == "FR")
    {
        for (int i = 0; i < 3; i++)
        {
            Color temp = cube[3][i][2];
            cube[3][i][2] = cube[5][i][2];
            cube[5][i][2] = cube[1][i][2];
            cube[1][i][2] = cube[4][i][2];
            cube[4][i][2] = temp;  
        }
        rotateFace(0, "R");
    }
    //front left
    else if (r == "FL")
    {
        for (int i = 0; i < 3; i++)
        {
            Color temp = cube[3][i][2];
            cube[3][i][2] = cube[4][i][2];
            cube[4][i][2] = cube[1][i][2];
            cube[1][i][2] = cube[5][i][2];
            cube[5][i][2] = temp;  
        }
        rotateFace(0, "L");
    }
    //back left
    else if (r == "BL")
    {
        for (int i = 0; i < 3; i++)
        {
            Color temp = cube[5][i][0];
            cube[5][i][0] = cube[3][i][0];
            cube[3][i][0] = cube[4][i][0];
            cube[4][i][0] = cube[1][i][0];
            cube[1][i][0] = temp;  
        }
        rotateFace(2, "L");
    }
    //back right
    else if (r == "BR")
    {
        for (int i = 0; i < 3; i++)
        {
            Color temp = cube[5][i][0];
            cube[5][i][0] = cube[1][i][0];
            cube[1][i][0] = cube[4][i][0];
            cube[4][i][0] = cube[3][i][0];
            cube[3][i][0] = temp;  
        }
        rotateFace(2, "R");
    }
    

}

void rotateFace(int f, string r)
{
    if(r == "L")
    {
        Color temp = cube[f][0][0];
        cube[f][0][0] = cube[f][0][2];
        cube[f][0][2] = cube[f][2][2];
        cube[f][2][2] = cube[f][2][0];
        cube[f][2][0] = temp;
        temp = cube[f][0][1];
        cube[f][0][1] = cube[f][1][2];
        cube[f][1][2] = cube[f][2][1];
        cube[f][2][1] = cube[f][1][0];
        cube[f][1][0] = temp;

    }
    else if(r == "R")
    {
        Color temp = cube[f][0][0];
        cube[f][0][0] = cube[f][2][0];
        cube[f][2][0] = cube[f][2][2];
        cube[f][2][2] = cube[f][0][2];
        cube[f][0][2] = temp;
        temp = cube[f][0][1];
        cube[f][0][1] = cube[f][1][0];
        cube[f][1][0] = cube[f][2][1];
        cube[f][2][1] = cube[f][1][0];
        cube[f][1][2] = temp;

    }

}

void print()
{
    map<Color,string> m;
    m[B] = "B";
    m[O] = "O";
    m[G] = "G";
    m[R] = "R";
    m[W] = "W";
    m[Y] = "Y";
    for (int face = 0; face < 6; face++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                cout<< m[cube[face][x][y]] << " ";
            }
            cout<< "\n";
        }
        cout<< "\n";
    } 
}

vector<float> getCube()
{
    vector<float> ret = vector<float>();
    for (int face = 0; face < 6; face++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                ret.push_back(cube[face][x][y]);
            }
        }
    } 
    return ret;
}

void randomize()
{
    string r[12] = {"UR", "UL", "DR", "DL", "RF", "RB", "LF", "LB", "FR", "FL", "BR", "BL"};
    int num = (rand() % 100) + 30;
    for (int i = 0; i < num; i++)
    {
        int temp = rand() % 12;
        rotate(r[temp]);
    }
}

};

class neuron
{
    public:
        float state;
        float bias;
        float learning_rate;
        vector<float> weights;

    neuron()
    {
        this->state = (float) rand()/RAND_MAX;
        this->bias = (float) rand()/RAND_MAX;
        learning_rate = 10;
    }
    void set_Weights(vector<float> w)
    {
        weights = w;
    }
    void setState(float state)
    {
        this->state = state;
    }
    void calculate(vector<float> values)
    {
        float sum = bias;
        for (int i = 0; i < values.size(); i++)
        {
            sum += weights[i] * values[i];
        }
        state = sigmoid(sum);
    }
    float sigmoid(float x)
    {
        return x / (1 + exp(-x));
    }
    float relu(float x)
    {
        if(x < 0){return 0;}else{return x;}
    }
    void print()
    {
        cout<< "state: "<< state << "bias: " << bias;
    }
    void addRandomness()
    {
        int adjuster = 1;
        vector<float> temp = vector<float>();
        for (int i = 0; i < weights.size(); i++)
        {
            if(rand() % 2 == 0){adjuster = -1;}
            float num = weights[i] + (((float) rand()/RAND_MAX) * learning_rate * adjuster);
            temp.push_back(num);
        }
        bias += ((float) rand()/RAND_MAX) * learning_rate * adjuster;
        set_Weights(temp);
        
    }

};

class layer
{
    public:
        vector<neuron> neurons;
    layer(int width)
    {
        for (int i = 0; i < width; i++)
        {
            neurons.push_back(neuron());
        }
    }
    neuron getNeuoron(int i)
    {
        return neurons[i];
    }
    void setNeuron(int i, float s)
    {
        neurons[i].state = s;
    }
    void print()
    {
        for (int i = 0; i < neurons.size(); i++)
        {
            neurons[i].print();
            cout<<"\n";
        }
    }
    int get_len()
    {
        return neurons.size();
    }
    vector<float> getStates()
    {
        vector<float> ret = vector<float>();
        for (int i = 0; i < neurons.size(); i++)
        {
            ret.push_back(neurons[i].state);
        }
        return ret;
    }
    void calculate(layer prevLayer)
    {
        for (int i = 0; i < get_len(); i++)
        {
            neurons[i].calculate(prevLayer.getStates());
        }
    }
    void initialize_weights(float prevlen)
    {
        for (int i = 0; i < get_len(); i++)
        {
            neurons[i].set_Weights(createRandomWeights(prevlen));
        }
        
    }
    vector<float> createRandomWeights(int len)
    {
        vector<float> weights = vector<float>();
        for (int i = 0; i < len; i++)
        {
            weights.push_back((float) rand()/RAND_MAX);
        }
        return weights;
    }
    void addRandomness()
    {
        for (int i = 0; i < get_len(); i++)
        {
            neurons[i].addRandomness();
        }
        
    }
    void initializeNeurons()
    {
        for (int i = i; i < get_len(); i++)
        {
            neurons[i] = neuron();
        }
        
    }

};

class network
{
    public:
    vector<layer> layers;
    network(vector<int> shape, rubix cube)
    {
       for (int i = 0; i < shape.size(); i++)
       {
            layers.push_back(layer(shape[i]));
       }
       cube.randomize();
       init(cube.getCube());
       
    }
    void insertInputs(vector<float> inputs)
    {
        for (int i = 0; i < inputs.size(); i++)
        {
            layers[0].setNeuron(i, inputs[i]);
        }
        
    }
    layer get_Layer(int i)
    {
        return layers[i];
    }
    void set_layer(int i, layer v)
    {
        layers[i] = v;
    }
    int get_len()
    {
        return layers.size();
    }
    void print()
    {
        for (int i = 0; i < layers.size(); i++)
        {
            layers[i].print();
            cout << "\n";
        }
        
    }
    vector<float> get_inputs()
    {
        return layers[0].getStates();
    }
    layer get_outputs()
    {
        return layers[layers.size() - 1];
    }
    void calculate()
    {
        for (int i = 1; i < layers.size(); i++)
        {
            layers[i].calculate(layers[i-1]);
        }
        
    }
    void initialize_weights()
    {
        for (int i = 1; i < layers.size(); i++)
        {
            layers[i].initialize_weights(layers[i-1].get_len());
        }
        
    }
    int selectOutput()
    {
        layer outputs = get_outputs();
        float max = 0;
        int index = 0;
        for (int i = 1; i < outputs.get_len(); i++)
        {
            if (outputs.getNeuoron(i).state > max)
            {
                max = outputs.getNeuoron(i).state;
                index = i;
            }
            
        }
        return index;
    }
    float score(rubix r, vector<string> moves)
    {
        float score = 0;
        for (int i = 2; i < moves.size(); i++)
        {
            if(moves[i] == moves[i-1] && moves[i-1] == moves[i-2])
            {
                score-=1000;
            }
        }
        rubix solved = rubix();
        vector<float> temp1 = r.getCube();
        vector<float> temp2 = solved.getCube();
        
        for (int i = 0; i < temp1.size(); i++)
        {
            if(temp1[i] == temp2[i])
            {
                score+=50;
            }
            else
            {
                score-=10;
            }
        }
        return score;
    }
    void addRandomness()
    {
        for (int i = 1; i < get_len(); i++)
        {
            layers[i].addRandomness();
        }
        
    }
    void initializeNeurons()
    {
        for (int i = i; i < get_len(); i++)
        {
            layers[i].initializeNeurons();
        }
        
    }
    void init(vector<float> inputs)
    {
        initializeNeurons();
        initialize_weights();
        insertInputs(inputs);
        calculate();
    }
};

void train(network net);

float train(network net, rubix r)
{
    string rotation[12] = {"UR", "UL", "DR", "DL", "RF", "RB", "LF", "LB", "FR", "FL", "BR", "BL"};
    vector<string> moves = vector<string>();
    for (int i = 0; i < 25; i++)
        {
            int index = net.selectOutput();
            r.rotate(rotation[index]);
            moves.push_back(rotation[index]);
            //cout << moves[i] << " ";
            net.insertInputs(r.getCube());
            net.calculate();
        }
        //cout << "\n";
    return net.score(r, moves);

    
}

int max(vector<float> v)
{
    float max = v[0];
    int index = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] > max)
        {
            max = v[i];
            index = i;
        }
    }
    return index;
    
}

int main()
{    

    srand(time(0));
    vector<int> shape = {54, 50, 50, 12};
    int agent_size = 20;
    rubix r = rubix();

    vector<network> puppets = vector<network>();

    for (int i = 0; i < agent_size; i++)
    {
        puppets.push_back(network(shape, r));
    }


    vector<float> results = vector<float>();
    for (int gen = 0; gen < 10; gen++)
    {
        
        results.clear();
        for (int i = 0; i < agent_size; i++)
        {
            r.randomize();
            results.push_back(train(puppets[i], r));
        }
        network bestNet = puppets[max(results)];
        for (int i = 0; i < agent_size; i++)
        {
            puppets.clear();
            for (int i = 0; i < agent_size; i++)
            {
                puppets.push_back(bestNet);
                puppets[i].addRandomness();
            }
        }
        cout << "next gen" <<"\n";
    }
}



