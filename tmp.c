


  int tmp1,tmp2,tmp_sum=0;
   for(int i=0;i<50;i++)
   {
       tmp1 = (transactions[i].S_UID + transactions[i].R_UID ) ;
       tmp 2 = tmp1 * (transactions[i].Amount/50) % pow(10,7) ;

       tmp_sum += tmp2;  
   }

     tmp_sum = tmp_sum%6 ;

     //replace digit in previousBlockhash
     

  
   int tmp_nonce = nonce%6 ;
        //replace digit in previousBlockhash

