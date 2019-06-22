package model;

public class Information extends Thread{
    private int distance = 0;
    private float speed = 0;
    private String pathFinding = "B";
    private boolean parking;
    private static final int CarHeight = 26;
    protected long time;

    public Information() {

    }

    public void setDistance(String distance) {
        lookIfCanPark(Integer.parseInt(distance),this.distance);
        this.distance = Integer.parseInt(distance);
    }

    public int getDistance() {
        return distance;
    }

    public void setPathFinding(String pathFinding) {
        this.pathFinding = pathFinding;
    }

    public String getPathFinding() {
        return pathFinding;
    }

    public void setSpeed(String speed) {
        this.speed = Float.valueOf(speed);
    }

    public float getSpeed() {
        return speed;
    }

    public boolean lookIfCanPark(int actualDistance, int lastDistance) {
        if (actualDistance >= lastDistance+10) {
            this.time = System.currentTimeMillis();
        }
        else if (actualDistance < lastDistance+10) {
            this.time = System.currentTimeMillis() - this.time;
            float length = this.time * this.speed;
            if (length >= this.CarHeight) {
                return true;
            }
        }
        return false;
    }
}
