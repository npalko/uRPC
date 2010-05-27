

    // client login produces Ticket Granting Ticket
    //    mac ox, unix: GSS-API
    //    windows: doesn't support GSS-API
    //    Microsoft SSPI (Security Support Provider Interface)
    //     provided by the OS
    //      unix: shared files
    //      windows:
    // obtain a session ticket
    //    send Ticket Granting Ticket + application info to KDC
    //    client caches session ticket, will not need another ticket until it
    //    session ticket expires
    
    