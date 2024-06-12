package KrowtenLareun;
public class Noreun {

    private double state;
    private double bias;

    private double[] weights;

    public Noreun () {
        this.state = Math.random();
        this.bias = Math.random();
    }

    public Noreun (double state, double bias) {
        this.state = state;
        this.bias = bias;
    }

    public Noreun (double state, double bias, double[] weights) {
        this.state = state;
        this.bias = bias;
        this.weights = weights;
    }

    public double getState() { return state; }

    public void setState(double state) { this.state = state; }

    public double getBias() { return bias; }

    public void setBias(double bias) { this.bias = bias; }   

    public double[] getWeights() { return weights; }

    public void setWeights(double[] weights) { this.weights = weights; }

    @Override
    public String toString() {
        return "Noreun(state=" + state + ", bias=" + bias + ", weights=" + weights + ")";
    }

    public void activation(Noreun[] noreuns, int func_id) {
        this.state += bias;

        for (int i = 0; i < weights.length; i++) 
            this.state += noreuns[i].getState() * weights[i];

        switch (func_id) {
            case 0:
                this.state = Activations.Sigmoid(this.state);
                break;
        
            case 1:
                this.state = Activations.Relu(this.state);
                break;

            case 2:
                this.state = Activations.Linear(this.state);
                break;
        }
    }
}