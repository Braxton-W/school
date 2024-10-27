package shapeAbstract;

abstract class Shape {
    protected String color;

    // abstract methods
    public abstract double getArea();
    public abstract double getPerimeter();

    // getter for color
    public String getColor() {
        return color;
    }

    // setter for color
    public void setColor(String color) {
        this.color = color;
    }
}
