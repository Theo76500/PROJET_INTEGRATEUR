package model;

import com.fazecast.jSerialComm.SerialPort;

import java.io.IOException;

public class ArduinoCommunication{

    private String portId = "";
    private SerialPort sp;
    private int BaudRate;
    public String message;

    public ArduinoCommunication(int baudRate, String portID) {
        this.portId = portID;
        this.BaudRate = baudRate;
        sp = SerialPort.getCommPort(portId);
        sp.setComPortParameters(BaudRate, 8, 1, 0);
        sp.setComPortTimeouts(SerialPort.TIMEOUT_WRITE_BLOCKING, 0, 0);
    }

    public Boolean OpenPort() {
        if (sp.openPort()) {
            System.out.println("Port is open !");
            return true;
        } else {
            System.out.println("Failed to open port...");
            return false;
        }
    }

    public Boolean ClosePort() {
        if (sp.closePort()) {
            System.out.println("Port is closed !");
            return true;
        } else {
            System.out.println("Failed to close port...");
            return false;
        }
    }

    public void Write() {
        for (Integer i = 0; i < 5; ++i) {
            try {
                sp.getOutputStream().write(i.byteValue());
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                sp.getOutputStream().flush();
            } catch (IOException e) {
                e.printStackTrace();
            }
            System.out.println("Value : " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public String Read() {
        String message = "";
        String newMessage = "";
        int len = 0;
        byte[] buffer = new byte[20];
        boolean end = false;
        boolean allow = false;
        int compt = 0;
        int tryRemaining = 10;

        while (!end) {
            try {
                len = sp.getInputStream().read(buffer);
            } catch (IOException e) {
                System.out.println("Cannot read the Input ! Retry !");
                if (tryRemaining == 0)
                    break;
                tryRemaining--;
            }
            if (len > 0) {
                message = new String(buffer);
            }
            len = 0;
            for(int i = 0; i < message.length(); i++) {
                if (message.charAt(i) == '#' && allow == false) {
                    allow = true;
                    compt = 0;
                }
                if (allow) {
                    newMessage = newMessage + (message.charAt(i));
                    compt++;
                }
                if (message.charAt(i) == ('@')) {
                    allow = false;
                    if(compt == 10) {
                        end = true;
                        break;
                    }
                    else {
                        compt = 0;
                        newMessage = "";
                    }
                }
            }
        }
        try {
            newMessage = newMessage.replace("#", "");
            newMessage = newMessage.replace("@", "");
            newMessage = newMessage.replace("*", "");
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println("Input was not read");
        }
            this.message =  newMessage;
        return this.message;
    }

    public void run() {
        while(true) {
            Read();
        }
    }
}
