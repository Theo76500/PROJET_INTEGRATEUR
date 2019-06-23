package contract;

import java.util.Observable;

public interface IModel {

	Observable getObservable();
	int getDistance();
	float getSpeed();
	String getPathFinding();
}
