package model;

import contract.IModel;
import java.util.Observable;

public final class Model extends Observable implements IModel {

	private ArduinoCommunication arduinoCommunication;
	private String message;
	public Information info;

	public Model() {
		arduinoCommunication = new ArduinoCommunication(9600, "COM12");
		info = new Information();
	}

	public Observable getObservable() {
		return this;
	}

	public void action() {
		message = arduinoCommunication.Read();
		char character = ' ';
		try {
			character = message.charAt(0);
		} catch (StringIndexOutOfBoundsException e) {
			System.out.println("Input was not read !");
		}
		switch (character) {
			case '1':
				info.setDistance(message.substring(1));
				break;
			case '2':
				info.setSpeed(message.substring(1));
				break;
			case '3':
				info.setPathFinding(message.substring(1));
				break;
			default:
				break;
		}
	}

	public boolean close() {
		if (arduinoCommunication.ClosePort())
			return true;
		else
			return false;
	}

	public boolean open() {
		if (arduinoCommunication.OpenPort())
			return true;
		else
			return false;
	}

	public int getDistance() {
		return info.getDistance();
	}

	public float getSpeed() {
		return info.getSpeed();
	}

	public String getPathFinding() {
		return info.getPathFinding();
	}

	public Boolean getParking() {
		return info.getParking();
	}
}
