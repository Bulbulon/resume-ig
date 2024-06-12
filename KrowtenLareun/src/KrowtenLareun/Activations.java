package KrowtenLareun;
public class Activations {

    public static double Sigmoid(double x) { return 1 / (1 + Math.exp(-x)); }

    public static double Relu(double x) { return x < 0 ? 0 : x; }

    public static double Linear(double x) { return x; }
    
}