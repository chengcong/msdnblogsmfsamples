
// {5E8FA2FC-2C05-440e-B3FF-936EA77B8F25}
DEFINE_GUID(MFVE_CATEGORY_AUDIO, 0x5e8fa2fc, 0x2c05, 0x440e, 0xb3, 0xff, 0x93, 0x6e, 0xa7, 0x7b, 0x8f, 0x25);

// {A4084BFA-3C0D-4ee2-B937-7061FC8346F5}
DEFINE_GUID(MFVE_CATEGORY_VIDEO, 0xa4084bfa, 0x3c0d, 0x4ee2, 0xb9, 0x37, 0x70, 0x61, 0xfc, 0x83, 0x46, 0xf5);

// {0DB97DF5-F935-4f0a-BF4A-75BA2DDF8CCA}
DEFINE_GUID(UNSHARP_PARAM_GAMMA, 0xdb97df5, 0xf935, 0x4f0a, 0xbf, 0x4a, 0x75, 0xba, 0x2d, 0xdf, 0x8c, 0xca);

// {3628DCB7-A0C4-4b7b-B1C6-B9D9A1804D82}
DEFINE_GUID(RESIZE_PARAM_DESTWIDTH, 0x3628dcb7, 0xa0c4, 0x4b7b, 0xb1, 0xc6, 0xb9, 0xd9, 0xa1, 0x80, 0x4d, 0x82);
// {E017EBFB-E333-4cde-918A-7AC42D90AC22}
DEFINE_GUID(RESIZE_PARAM_DESTHEIGHT, 0xe017ebfb, 0xe333, 0x4cde, 0x91, 0x8a, 0x7a, 0xc4, 0x2d, 0x90, 0xac, 0x22);
// {73BD80BB-24BE-42bc-9ED9-04F156226642}
DEFINE_GUID(RESIZE_PARAM_CROP, 0x73bd80bb, 0x24be, 0x42bc, 0x9e, 0xd9, 0x4, 0xf1, 0x56, 0x22, 0x66, 0x42);

// {18198B0A-69AC-429B-9C81-71D969596783}
DEFINE_GUID(VOLCOMP_PARAM_FACTOR, 0x18198B0A, 0x69AC, 0x429B, 0x9C, 0x81, 0x71, 0xD9, 0x69, 0x59, 0x67, 0x83);

STDAPI MFVEMFTGetInfo(CLSID clsidMFT, __deref_out LPWSTR* ppszName, __out LPWSTR* ppszDescription);
STDAPI MFVEMFTEnum(GUID guidCategory, __deref_out CLSID** ppclsidMFT, __out UINT32* pcMFTs);
STDAPI MFVEMFTRegister(CLSID clsidMFT, GUID guidCategory, __in LPWSTR pszName, __in LPWSTR pszDescription);
STDAPI MFVEMFTUnregister(CLSID clsidMFT);