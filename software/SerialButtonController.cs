// Required Libraries
using System;
using System.IO.Ports;
using UnityEngine;
using UnityEngine.UI;

public class SerialButtonController : MonoBehaviour
{
    public string portName = "COM7"; // Replace with your actual port
    public int baudRate = 115200;

    private SerialPort serialPort;

    void Start()
    {
        try
        {
            serialPort = new SerialPort(portName, baudRate);
            serialPort.Open();
            serialPort.ReadTimeout = 100;
            Debug.Log("Serial Port Opened: " + portName);
        }
        catch (Exception e)
        {
            Debug.LogError("Failed to open serial port: " + e.Message);
        }
    }

    public void SendPatternCommand()
    {
        if (serialPort != null && serialPort.IsOpen)
        {
            serialPort.WriteLine("ACTIVATE_PATTERN");
            Debug.Log("Command Sent: ACTIVATE_PATTERN");
        }
        else
        {
            Debug.LogError("Serial Port is not open.");
        }
    }

    void OnApplicationQuit()
    {
        if (serialPort != null && serialPort.IsOpen)
        {
            serialPort.Close();
        }
    }
}