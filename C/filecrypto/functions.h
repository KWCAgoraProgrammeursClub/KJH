#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

int absorb_file
  (char* path, unsigned char** buf, unsigned* buflen);

void derive_key 
  (unsigned char* source, unsigned len, unsigned char key[ 32 ]);

void hmac
  (
    unsigned char key[ 32 ],
    unsigned char* data,
    unsigned data_length,
    unsigned char hmac[ 32 ]
  );

void random_iv
  (unsigned char in[ 16 ], unsigned char iv[ 16 ]);

int encapsulate
  (
    char* path,
    unsigned char* payload,
    unsigned payload_size,
    unsigned char iv[ 16 ],
    unsigned char Ke[ 32 ],
    unsigned char Ka[ 32 ]
  );

int decapsulate
  (
    char* path,
    unsigned char* ciphertext,
    unsigned ciphertext_length,
    unsigned char* iv,
    unsigned char* Ke,
    unsigned char* Ka,
    unsigned char* hmac
  );

int safe_memcmp
  (unsigned char* mem1, unsigned char* mem2, unsigned size);

#endif
