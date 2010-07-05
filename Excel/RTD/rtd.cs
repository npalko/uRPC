//

// Required Assemblies
//  System.Windows.Forms 2.0.0
//  Microsoft.Office.Interop.Excel 12.0.0.0

using System;
using System.Runtime.InteropServices;
using System.Windows.Forms; // needed for timer
using Microsoft.Office.Interop.Excel;

namespace rtd {
  [ComVisible(true), ProgId("uRPC.ExcelRTDServer")]
  public class RTDTest : IRtdServer {
    public int ServerStart(IRTDUpdateEvent callback) {
      // ServerStart is the first method called by Excel and is where we 
      // prepare the RTD server. In particular we set the callback member 
      // variable and prepare the timer. Notice that the timer is not yet 
      // enabled. Returning 1 indicates that everything is fine. 

      m_callback = callback;
      m_timer = new Timer();
      m_timer.Tick += new EventHandler(TimerEventHandler);
      m_timer.Interval = 2000;

      return 1;
    }
    public void ServerTerminate() {
      // ServerTerminate is called when Excel is ready to unload the RTD 
      // server. Here we simply release the timer.

      if (null != m_timer) {
        m_timer.Dispose();
        m_timer = null;
      }
    }
    public object ConnectData(int topicId, ref Array strings, ref bool newValues) {
      // ConnectData is called for each “topic” that Excel wishes to 
      // “subscribe” to. It is called once for every unique subscription. As 
      // should be obvious, this implementation assumes there will only be a 
      // single topic. In a future post I’ll talk about handling multiple 
      // topics. ConnectData also starts the timer and returns an initial 
      // value that Excel can display.

      m_topicId = topicId;
      m_timer.Start();
      return GetTime();
    }
    public void DisconnectData(int topicId) {
      // DisconnectData is called to tell the RTD server that Excel is no 
      // longer interested in data for the particular topic. In this case, we
      // simply stop the timer to prevent the RTD server from notifying 
      // Excel of any further updates.

      m_timer.Stop();
    }
    public Array RefreshData(ref int topicCount) {
      // RefreshData is called when Excel is ready to retrieve any updated 
      // data for the topics that it has previously subscribed to via 
      // ConnectData. The implementation looks a bit strange. That’s mainly 
      // because Excel is expecting the data as a COM SAFEARRAY. Although it 
      // isn’t pretty, The CLR’s COM infrastructure does a commendable job of 
      // marshalling the data for you. All you need to do is populate the 
      // two-dimensional array with the topic Ids and values and set the 
      // topicCount parameter to the number of topics that are included in 
      // the update. Finally, the timer is restarted before returning the 
      // data.

      object[,] data = new object[2, 1];
      data[0, 0] = m_topicId;
      data[1, 0] = GetTime();

      topicCount = 1;

      m_timer.Start();
      return data;
    }
    public int Heartbeat() {
      // Heartbeat is called by Excel if it hasn’t received any updates 
      // recently in an attempt to determine whether your RTD server is still 
      // OK. Returning 1 indicates that everything is fine. 

      return 1;
    }
    private IRTDUpdateEvent m_callback;
    private Timer m_timer;
    private int m_topicId;

    // m_callback: holds onto a reference to the callback interface 
    // provided by Excel; used to let Excel know new data is available
    // m_timer: Windows.Forms timer used to periodically notify Excel via
    // the callback interface. This timer is optional and you are free to
    // implement update notifications any way you want.
    // m_topicId: identifies the topic that Excel is "subscribing" to
  
    private void TimerEventHandler(object sender, EventArgs args) {
      // TimerEventHandler is the private method that is called when the 
      // timer Tick event is raised. It stops the timer and uses the callback
      // interface to let Excel know that updates are available. Stopping the 
      // timer is important since we don’t want to call UpdateNotify
      // repeatedly. 

      m_timer.Stop();
      m_callback.UpdateNotify();
    }
    private string GetTime() {
      // GetTime is a private method used to get a formatted time string that 
      // represents the data to display in Excel. As you can imagine, this 
      // RTD server simply updates the time in the cell roughly every two 
      // seconds.

      return DateTime.Now.ToString("hh:mm:ss:ff");
    }
  }
}
