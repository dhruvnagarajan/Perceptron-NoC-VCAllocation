class Log {
    
    public:

        int tileID;
        int latency;

        void setLog(int _tileID, int _latency) {
            tileID = _tileID;
            latency = _latency;
        }

        int getTileID() { return tileID; }

        int getLatency() { return latency; }
};