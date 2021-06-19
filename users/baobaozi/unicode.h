#pragma once
#include "quantum.h"

// clang-format off
#define FOREACH_UNICODE(M) \
    M(UALP,  0x0391) /* Α */ \
    M(UBET,  0x0392) /* Β */ \
    M(UGAM,  0x0393) /* Γ */ \
    M(UDEL,  0x0394) /* Δ */ \
    M(UEPS,  0x0395) /* Ε */ \
    M(UZET,  0x0396) /* Ζ */ \
    M(UETA,  0x0397) /* Η */ \
    M(UTHE,  0x0398) /* Θ */ \
    M(UIOT,  0x0399) /* Ι */ \
    M(UKAP,  0x039A) /* Κ */ \
    M(ULAM,  0x039B) /* Λ */ \
    M(UMU,   0x039C) /* M */ \
    M(UNU,   0x039D) /* Ν */ \
    M(UXI,   0x039E) /* Ξ */ \
    M(UOMI,  0x039F) /* Ο */ \
    M(UPI,   0x03A0) /* Π */ \
    M(URHO,  0x03A1) /* Ρ */ \
    M(USIG,  0x03A3) /* Σ */ \
    M(UTAU,  0x03A4) /* Τ */ \
    M(UUPS,  0x03A5) /* Υ */ \
    M(UPHI,  0x03A6) /* Φ */ \
    M(UCHI,  0x03A7) /* Χ */ \
    M(UPSI,  0x03A8) /* Ψ */ \
    M(UOME,  0x03A9) /* Ω */ \
    M(LALP,  0x03B1) /* α */ \
    M(LBET,  0x03B2) /* β */ \
    M(LGAM,  0x03B3) /* γ */ \
    M(LDEL,  0x03B4) /* δ */ \
    M(LEPS,  0x03B5) /* ε */ \
    M(LZET,  0x03B6) /* ζ */ \
    M(LETA,  0x03B7) /* η */ \
    M(LTHE,  0x03B8) /* θ */ \
    M(LIOT,  0x03B9) /* ι */ \
    M(LKAP,  0x03BA) /* κ */ \
    M(LLAM,  0x03BB) /* λ */ \
    M(LMU,   0x03BC) /* μ */ \
    M(LNU,   0x03BD) /* ν */ \
    M(LXI,   0x03BE) /* ξ */ \
    M(LOMI,  0x03BF) /* ο */ \
    M(LPI,   0x03C0) /* π */ \
    M(LRHO,  0x03C1) /* ρ */ \
    M(LSIG,  0x03C3) /* σ */ \
    M(LTAU,  0x03C4) /* τ */ \
    M(LUPS,  0x03C5) /* υ */ \
    M(LPHI,  0x03C6) /* φ */ \
    M(LCHI,  0x03C7) /* χ */ \
    M(LPSI,  0x03C8) /* ψ */ \
    M(LOME,  0x03C9) /* ω */ \
    M(UAH,   0x0410) /* А */ \
    M(UBE,   0x0411) /* Б */ \
    M(UVE,   0x0412) /* В */ \
    M(UGHE,  0x0413) /* Г */ \
    M(UDE,   0x0414) /* Д */ \
    M(UIE,   0x0415) /* Е */ \
    M(UIO,   0x0401) /* Ё */ \
    M(UZHE,  0x0416) /* Ж */ \
    M(UZE,   0x0417) /* З */ \
    M(UIH,   0x0418) /* И */ \
    M(USIH,  0x0419) /* Й */ \
    M(UKA,   0x041A) /* К */ \
    M(UEL,   0x041B) /* Л */ \
    M(UEM,   0x041C) /* М */ \
    M(UEN,   0x041D) /* Н */ \
    M(UOH,   0x041E) /* О */ \
    M(UPE,   0x041F) /* П */ \
    M(UER,   0x0420) /* Р */ \
    M(UES,   0x0421) /* С */ \
    M(UTE,   0x0422) /* Т */ \
    M(UUU,   0x0423) /* У */ \
    M(UEF,   0x0424) /* Ф */ \
    M(UHA,   0x0425) /* Х */ \
    M(UTSE,  0x0426) /* Ц */ \
    M(UCHE,  0x0427) /* Ч */ \
    M(USHA,  0x0428) /* Ш */ \
    M(USCHA, 0x0429) /* Щ */ \
    M(UHARD, 0x042A) /* Ъ */ \
    M(UYERU, 0x042B) /* Ы */ \
    M(USOFT, 0x042C) /* Ь */ \
    M(UEH,   0x042D) /* Э */ \
    M(UYU,   0x042E) /* Ю */ \
    M(UYA,   0x042F) /* Я */ \
    M(LAH,   0x0430) /* а */ \
    M(LBE,   0x0431) /* б */ \
    M(LVE,   0x0432) /* в */ \
    M(LGHE,  0x0433) /* г */ \
    M(LDE,   0x0434) /* д */ \
    M(LIE,   0x0435) /* е */ \
    M(LIO,   0x0451) /* ё */ \
    M(LZHE,  0x0436) /* ж */ \
    M(LZE,   0x0437) /* з */ \
    M(LIH,   0x0438) /* и */ \
    M(LSIH,  0x0439) /* й */ \
    M(LKA,   0x043A) /* к */ \
    M(LEL,   0x043B) /* л */ \
    M(LEM,   0x043C) /* м */ \
    M(LEN,   0x043D) /* н */ \
    M(LOH,   0x043E) /* о */ \
    M(LPE,   0x043F) /* п */ \
    M(LER,   0x0440) /* р */ \
    M(LES,   0x0441) /* с */ \
    M(LTE,   0x0442) /* т */ \
    M(LUU,   0x0443) /* у */ \
    M(LEF,   0x0444) /* ф */ \
    M(LHA,   0x0445) /* х */ \
    M(LTSE,  0x0446) /* ц */ \
    M(LCHE,  0x0447) /* ч */ \
    M(LSHA,  0x0448) /* ш */ \
    M(LSCHA, 0x0449) /* щ */ \
    M(LHARD, 0x044A) /* ъ */ \
    M(LYERU, 0x044B) /* ы */ \
    M(LSOFT, 0x044C) /* ь */ \
    M(LEH,   0x044D) /* э */ \
    M(LYU,   0x044E) /* ю */ \
    M(LYA,   0x044F) /* я */ \
    M(FE,    0x16A0) /* ᚠ */ \
    M(UR,    0x16A2) /* ᚢ */ \
    M(THURS, 0x16A6) /* ᚦ */ \
    M(ANSUZ, 0x16A8) /* ᚨ */ \
    M(RAIDO, 0x16B1) /* ᚱ */ \
    M(KAUNA, 0x16B2) /* ᚲ */ \
    M(GEBO,  0x16B7) /* ᚷ */ \
    M(WUNJO, 0x16B9) /* ᚹ */ \
    M(HAGLZ, 0x16BA) /* ᚺ */ \
    M(NAUDZ, 0x16BE) /* ᚾ */ \
    M(ISAZ,  0x16C1) /* ᛁ */ \
    M(JERAN, 0x16C3) /* ᛃ */ \
    M(IWAZ,  0x16C7) /* ᛇ */ \
    M(PERTH, 0x1F60A) /* 😊 */ \
    M(ALGIZ, 0x16C9) /* ᛉ */ \
    M(SOWIL, 0x16CA) /* ᛊ */ \
    M(TIWAZ, 0x16CF) /* ᛏ */ \
    M(BEORC, 0x16D2) /* ᛒ */ \
    M(EHWAZ, 0x16D6) /* ᛖ */ \
    M(MANNZ, 0x16D7) /* ᛗ */ \
    M(LAUKZ, 0x16DA) /* ᛚ */ \
    M(INGWZ, 0x16DC) /* ᛜ */ \
    M(DAGAZ, 0x16DE) /* ᛞ */ \
    M(ETHEL, 0x16DF) /* ᛟ */ \
    M(JRO,   0x308D) /* ろ */ \
    M(JWA,   0x308F) /* わ */ \
    M(JNU,   0x306C) /* ぬ */ \
    M(JHU,   0x3075) /* ふ */ \
    M(JA,    0x3042) /* あ */ \
    M(JU,    0x3046) /* う */ \
    M(JE,    0x3048) /* え */ \
    M(JO,    0x304A) /* お */ \
    M(JYA,   0x3084) /* や */ \
    M(JYU,   0x3086) /* ゆ */ \
    M(JYO,   0x3088) /* よ */ \
    M(JHO,   0x307B) /* ほ */ \
    M(JHE,   0x3078) /* へ */ \
    M(JMU,   0x3080) /* む */ \
    M(JTA,   0x305F) /* た */ \
    M(JTE,   0x3066) /* て */ \
    M(JI,    0x3044) /* い */ \
    M(JSU,   0x3059) /* す */ \
    M(JKA,   0x3095) /* ゕ */ \
    M(JN,    0x3093) /* ん */ \
    M(JNA,   0x306A) /* な */ \
    M(JNI,   0x306B) /* に */ \
    M(JRA,   0x3089) /* ら */ \
    M(JSE,   0x305B) /* せ */ \
    M(JVV,   0x309B) /* ゛*/ \
    M(JSV,   0x309C) /* ゜*/ \
    M(JTI,   0x3061) /* ち */ \
    M(JTO,   0x3068) /* と */ \
    M(JSI,   0x3057) /* し */ \
    M(JHA,   0x306F) /* は */ \
    M(JKI,   0x304D) /* き */ \
    M(JKU,   0x304F) /* く */ \
    M(JMA,   0x307E) /* ま */ \
    M(JNO,   0x306E) /* の */ \
    M(JRI,   0x308A) /* り */ \
    M(JRE,   0x308C) /* れ */ \
    M(JKE,   0x3051) /* け */ \
    M(JTU,   0x3064) /* つ */ \
    M(JSA,   0x3055) /* さ */ \
    M(JSO,   0x305D) /* そ */ \
    M(JHI,   0x3072) /* ひ */ \
    M(JKO,   0x3053) /* こ */ \
    M(JMI,   0x307F) /* み */ \
    M(JMO,   0x3082) /* も */ \
    M(JNE,   0x306D) /* ね */ \
    M(JRU,   0x308B) /* る */ \
    M(JME,   0x3081) /* め */ \
    M(ALEF,  0x05D0) /* א */ \
    M(BET,   0x05D1) /* ב */ \
    M(GIMEL, 0x05D2) /* ג */ \
    M(DALET, 0x05D3) /* ד */ \
    M(HE,    0x05D4) /* ה */ \
    M(VAV,   0x05D5) /* ו */ \
    M(ZAYIN, 0x05D6) /* ז */ \
    M(CHET,  0x05D7) /* ח */ \
    M(TET,   0x05D8) /* ט */ \
    M(YOD,   0x05D9) /* י */ \
    M(KAF,   0x05DB) /* כ */ \
    M(LAMED, 0x05DC) /* ל */ \
    M(MEM,   0x05DE) /* מ */ \
    M(NUN,   0x05E0) /* נ */ \
    M(SAMCH, 0x05E1) /* ס */ \
    M(AYIN,  0x05E2) /* ע */ \
    M(PE,    0x05E4) /* פ */ \
    M(TZADI, 0x05E6) /* צ */ \
    M(KOF,   0x05E7) /* ק */ \
    M(RESH,  0x05E8) /* ר */ \
    M(SHIN,  0x05E9) /* ש */ \
    M(TAV,   0x05EA) /* ת */
// clang-format on

#define UC_KEYCODE(name, code)  name = UC(code),        // LALP = UC(0x03B1),

#define UCM_NAME(name, code)    UCM_ ## name,           // UCM_LALP,
#define UCM_ENTRY(name, code)   [UCM_ ## name] = code,  // [UCM_LALP] = 0x03B1,
#define UCM_KEYCODE(name, code) name = X(UCM_ ## name), // LALP = X(UCM_LALP)

#if defined(UNICODE_ENABLE)
enum unicode_keycodes {
    FOREACH_UNICODE(UC_KEYCODE)
};
#elif defined(UNICODEMAP_ENABLE)
enum unicode_names {
    FOREACH_UNICODE(UCM_NAME)
};

extern const uint32_t PROGMEM unicode_map[];

enum unicode_keycodes {
    FOREACH_UNICODE(UCM_KEYCODE)
};
#endif


#define ALPHA XP(LALP, UALP)
#define BETA  XP(LBET, UBET)
#define GAMMA XP(LGAM, UGAM)
#define DELTA XP(LDEL, UDEL)
#define EPSLN XP(LEPS, UEPS)
#define ZETA  XP(LZET, UZET)
#define ETA   XP(LETA, UETA)
#define THETA XP(LTHE, UTHE)
#define IOTA  XP(LIOT, UIOT)
#define KAPPA XP(LKAP, UKAP)
#define LAMBD XP(LLAM, ULAM)
#define GMU   XP(LMU,  UMU)
#define NU    XP(LNU,  UNU)
#define XI    XP(LXI,  UXI)
#define OMCRN XP(LOMI, UOMI)
#define PI    XP(LPI,  UPI)
#define RHO   XP(LRHO, URHO)
#define SIGMA XP(LSIG, USIG)
#define TAU   XP(LTAU, UTAU)
#define UPSLN XP(LUPS, UUPS)
#define PHI   XP(LPHI, UPHI)
#define CHI   XP(LCHI, UCHI)
#define PSI   XP(LPSI, UPSI)
#define OMEGA XP(LOME, UOME)

#define AH   XP(LAH,   UAH)
#define BE   XP(LBE,   UBE)
#define VE   XP(LVE,   UVE)
#define GHE  XP(LGHE,  UGHE)
#define DE   XP(LDE,   UDE)
#define IE   XP(LIE,   UIE)
#define IO   XP(LIO,   UIO)
#define ZHE  XP(LZHE,  UZHE)
#define ZE   XP(LZE,   UZE)
#define IH   XP(LIH,   UIH)
#define SIH  XP(LSIH,  USIH)
#define KA   XP(LKA,   UKA)
#define EL   XP(LEL,   UEL)
#define EM   XP(LEM,   UEM)
#define EN   XP(LEN,   UEN)
#define OH   XP(LOH,   UOH)
#define PE   XP(LPE,   UPE)
#define ER   XP(LER,   UER)
#define ES   XP(LES,   UES)
#define TE   XP(LTE,   UTE)
#define UU   XP(LUU,   UUU)
#define EF   XP(LEF,   UEF)
#define HA   XP(LHA,   UHA)
#define TSE  XP(LTSE,  UTSE)
#define CHE  XP(LCHE,  UCHE)
#define SHA  XP(LSHA,  USHA)
#define SCHA XP(LSCHA, USCHA)
#define HARD XP(LHARD, UHARD)
#define YERU XP(LYERU, UYERU)
#define SOFT XP(LSOFT, USOFT)
#define EH   XP(LEH,   UEH)
#define YU   XP(LYU,   UYU)
#define YA   XP(LYA,   UYA)
