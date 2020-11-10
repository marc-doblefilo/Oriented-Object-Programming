class Dados{
    private:
        int dice1_;
        int d1_counter_;
        float d1_media_;
        int dice2_;
        int d2_counter_;
        float d2_media_;
        int d1_vect_[5] = {0, 0, 0, 0, 0};
        int d2_vect_[5] = {0, 0, 0, 0, 0};
    public:
        Dados();
        int getDado1();
        int getDado2();
        bool setDado1(int n);
        bool setDado2(int n);
        int getSuma();
        void lanzamiento();
        int getDiferencia();
        int getLanzamientos1();
        int getLanzamientos2();
        float getMedia1();
        float getMedia2();
        int *getUltimos1(int arr[]);
        int *getUltimos2(int arr[]);
};