#include "nyastega8.h"

#include <random>
#include <unordered_map>

namespace nyastega8 {

std::wstring encode(const std::string &top) {
    static std::random_device device;
    static std::default_random_engine engine{device()};
    static std::uniform_int_distribution distribution(0, 5);
    static const auto dict = L"的是不一有我了在个人以可要用时上能就为这么你大好中和到后会多下生也如他出来对过发还都说现分子没方天很成什自点果年于家性行问法面最小看动去地高们国而作得经开学样定等因所水那体心或理想加里但前之种道怎物本机其月应日常进间比同手电些然力只情意次内请者做起入重主知题合量关长部度当使外新公少业工病无期事件与感打己实正系她全吗给三相化级文明数谢女位两通别该网金话血回解原从治保身再第品产每提较制啊白把宝食将色吃装表及着放选接单服爱名平气几头老结更务此买疗需安才西觉口并特二变直证候器由质利车药哪程已式管清注资基真效又友号何";
    static const auto separator = L"！。，…~？";
    std::wstring bottom;
    int j = 0;
    for (const uint8_t byte: top) {
        bottom += dict[byte];
        if (distribution(engine, decltype(distribution)::param_type{1, 10 - j}) == 1) {
            bottom += separator[distribution(engine)];
            j = 0;
        } else ++j;
    }
    return bottom;
}

std::string decode(const std::wstring &bottom) {
    static const std::unordered_map<wchar_t, uint8_t> map = {
        {L'的', 0},
        {L'是', 1},
        {L'不', 2},
        {L'一', 3},
        {L'有', 4},
        {L'我', 5},
        {L'了', 6},
        {L'在', 7},
        {L'个', 8},
        {L'人', 9},
        {L'以', 10},
        {L'可', 11},
        {L'要', 12},
        {L'用', 13},
        {L'时', 14},
        {L'上', 15},
        {L'能', 16},
        {L'就', 17},
        {L'为', 18},
        {L'这', 19},
        {L'么', 20},
        {L'你', 21},
        {L'大', 22},
        {L'好', 23},
        {L'中', 24},
        {L'和', 25},
        {L'到', 26},
        {L'后', 27},
        {L'会', 28},
        {L'多', 29},
        {L'下', 30},
        {L'生', 31},
        {L'也', 32},
        {L'如', 33},
        {L'他', 34},
        {L'出', 35},
        {L'来', 36},
        {L'对', 37},
        {L'过', 38},
        {L'发', 39},
        {L'还', 40},
        {L'都', 41},
        {L'说', 42},
        {L'现', 43},
        {L'分', 44},
        {L'子', 45},
        {L'没', 46},
        {L'方', 47},
        {L'天', 48},
        {L'很', 49},
        {L'成', 50},
        {L'什', 51},
        {L'自', 52},
        {L'点', 53},
        {L'果', 54},
        {L'年', 55},
        {L'于', 56},
        {L'家', 57},
        {L'性', 58},
        {L'行', 59},
        {L'问', 60},
        {L'法', 61},
        {L'面', 62},
        {L'最', 63},
        {L'小', 64},
        {L'看', 65},
        {L'动', 66},
        {L'去', 67},
        {L'地', 68},
        {L'高', 69},
        {L'们', 70},
        {L'国', 71},
        {L'而', 72},
        {L'作', 73},
        {L'得', 74},
        {L'经', 75},
        {L'开', 76},
        {L'学', 77},
        {L'样', 78},
        {L'定', 79},
        {L'等', 80},
        {L'因', 81},
        {L'所', 82},
        {L'水', 83},
        {L'那', 84},
        {L'体', 85},
        {L'心', 86},
        {L'或', 87},
        {L'理', 88},
        {L'想', 89},
        {L'加', 90},
        {L'里', 91},
        {L'但', 92},
        {L'前', 93},
        {L'之', 94},
        {L'种', 95},
        {L'道', 96},
        {L'怎', 97},
        {L'物', 98},
        {L'本', 99},
        {L'机', 100},
        {L'其', 101},
        {L'月', 102},
        {L'应', 103},
        {L'日', 104},
        {L'常', 105},
        {L'进', 106},
        {L'间', 107},
        {L'比', 108},
        {L'同', 109},
        {L'手', 110},
        {L'电', 111},
        {L'些', 112},
        {L'然', 113},
        {L'力', 114},
        {L'只', 115},
        {L'情', 116},
        {L'意', 117},
        {L'次', 118},
        {L'内', 119},
        {L'请', 120},
        {L'者', 121},
        {L'做', 122},
        {L'起', 123},
        {L'入', 124},
        {L'重', 125},
        {L'主', 126},
        {L'知', 127},
        {L'题', 128},
        {L'合', 129},
        {L'量', 130},
        {L'关', 131},
        {L'长', 132},
        {L'部', 133},
        {L'度', 134},
        {L'当', 135},
        {L'使', 136},
        {L'外', 137},
        {L'新', 138},
        {L'公', 139},
        {L'少', 140},
        {L'业', 141},
        {L'工', 142},
        {L'病', 143},
        {L'无', 144},
        {L'期', 145},
        {L'事', 146},
        {L'件', 147},
        {L'与', 148},
        {L'感', 149},
        {L'打', 150},
        {L'己', 151},
        {L'实', 152},
        {L'正', 153},
        {L'系', 154},
        {L'她', 155},
        {L'全', 156},
        {L'吗', 157},
        {L'给', 158},
        {L'三', 159},
        {L'相', 160},
        {L'化', 161},
        {L'级', 162},
        {L'文', 163},
        {L'明', 164},
        {L'数', 165},
        {L'谢', 166},
        {L'女', 167},
        {L'位', 168},
        {L'两', 169},
        {L'通', 170},
        {L'别', 171},
        {L'该', 172},
        {L'网', 173},
        {L'金', 174},
        {L'话', 175},
        {L'血', 176},
        {L'回', 177},
        {L'解', 178},
        {L'原', 179},
        {L'从', 180},
        {L'治', 181},
        {L'保', 182},
        {L'身', 183},
        {L'再', 184},
        {L'第', 185},
        {L'品', 186},
        {L'产', 187},
        {L'每', 188},
        {L'提', 189},
        {L'较', 190},
        {L'制', 191},
        {L'啊', 192},
        {L'白', 193},
        {L'把', 194},
        {L'宝', 195},
        {L'食', 196},
        {L'将', 197},
        {L'色', 198},
        {L'吃', 199},
        {L'装', 200},
        {L'表', 201},
        {L'及', 202},
        {L'着', 203},
        {L'放', 204},
        {L'选', 205},
        {L'接', 206},
        {L'单', 207},
        {L'服', 208},
        {L'爱', 209},
        {L'名', 210},
        {L'平', 211},
        {L'气', 212},
        {L'几', 213},
        {L'头', 214},
        {L'老', 215},
        {L'结', 216},
        {L'更', 217},
        {L'务', 218},
        {L'此', 219},
        {L'买', 220},
        {L'疗', 221},
        {L'需', 222},
        {L'安', 223},
        {L'才', 224},
        {L'西', 225},
        {L'觉', 226},
        {L'口', 227},
        {L'并', 228},
        {L'特', 229},
        {L'二', 230},
        {L'变', 231},
        {L'直', 232},
        {L'证', 233},
        {L'候', 234},
        {L'器', 235},
        {L'由', 236},
        {L'质', 237},
        {L'利', 238},
        {L'车', 239},
        {L'药', 240},
        {L'哪', 241},
        {L'程', 242},
        {L'已', 243},
        {L'式', 244},
        {L'管', 245},
        {L'清', 246},
        {L'注', 247},
        {L'资', 248},
        {L'基', 249},
        {L'真', 250},
        {L'效', 251},
        {L'又', 252},
        {L'友', 253},
        {L'号', 254},
        {L'何', 255}
    };
    std::string top;
    for (auto character: bottom) {
        const auto it = map.find(character);
        if (it != map.end()) top += it->second;
    }
    return top;
}

} // nyastega8
