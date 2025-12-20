#pragma once

enum unicode_names {
    EA1,
    EA1M,
    EA2,
    EA2M,
    AA1,
    AA1M,
    EA3,
    EA3M,
    CA1,
    CA1M,
    OA1,
    OA1M,
    AA2,
    AA2M,
    IA1,
    IA1M,
    UA1,
    UA1M,
    UA2,
    UA2M,
    IA2,
    IA2M,
    UA3,
    UA3M,
    EA4,
    EA4M,
    OA2,
    OA2M,
    EURO
};

const uint32_t PROGMEM unicode_map[] = {
    [EA1]  = 0x00E9, // é
    [EA1M] = 0x00C9, // É
    [EA2]  = 0x00E8, // è
    [EA2M] = 0x00C8, // È
    [AA1]  = 0x00E0, // à
    [AA1M] = 0x00C0, // À
    [EA3]  = 0x00EA, // ê
    [EA3M] = 0x00CA, // Ê
    [CA1]  = 0x00E7, // ç
    [CA1M] = 0x00C7, // Ç
    [OA1]  = 0x00F4, // ô
    [OA1M] = 0x00D4, // Ô
    [AA2]  = 0x00E2, // â
    [AA2M] = 0x00C2, // Â
    [IA1]  = 0x00EE, // î
    [IA1M] = 0x00CE, // Î
    [UA1]  = 0x00FB, // û
    [UA1M] = 0x00DB, // Û
    [UA2]  = 0x00F9, // ù
    [UA2M] = 0x00D9, // Ù
    [IA2]  = 0x00EF, // ï
    [IA2M] = 0x00CF, // Ï
    [UA3]  = 0x00FC, // ü
    [UA3M] = 0x00DC, // Ü
    [EA4]  = 0x00EB, // ë
    [EA4M] = 0x00CB, // Ë
    [OA2]  = 0x0153, // œ
    [OA2M] = 0x0152, // Œ
    [EURO] = 0x20AC, // €
};

// UP(lower, upper) - unicode pair for shift-aware keys
#define FR_EA1 UP(EA1, EA1M)
#define FR_EA2 UP(EA2, EA2M)
#define FR_AA1 UP(AA1, AA1M)
#define FR_EA3 UP(EA3, EA3M)
#define FR_CA1 UP(CA1, CA1M)
#define FR_OA1 UP(OA1, OA1M)
#define FR_AA2 UP(AA2, AA2M)
#define FR_IA1 UP(IA1, IA1M)
#define FR_UA1 UP(UA1, UA1M)
#define FR_UA2 UP(UA2, UA2M)
#define FR_IA2 UP(IA2, IA2M)
#define FR_UA3 UP(UA3, UA3M)
#define FR_EA4 UP(EA4, EA4M)
#define FR_OA2 UP(OA2, OA2M)

// UM(index) - single unicode character (uppercase variants for Adjust layer)
#define FR_EM1 UM(EA1M)
#define FR_EM2 UM(EA2M)
#define FR_AM1 UM(AA1M)
#define FR_EM3 UM(EA3M)
#define FR_CM1 UM(CA1M)
#define FR_OM1 UM(OA1M)
#define FR_AM2 UM(AA2M)
#define FR_IM1 UM(IA1M)
#define FR_UM1 UM(UA1M)
#define FR_UM2 UM(UA2M)
#define FR_IM2 UM(IA2M)
#define FR_UM3 UM(UA3M)
#define FR_EM4 UM(EA4M)
#define FR_OM2 UM(OA2M)

#define EURO UM(EURO)
