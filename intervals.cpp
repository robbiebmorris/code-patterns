//
// INTERVALS
//


// There are 6 possibilities for how two intervals can be positioned in 
// relation to each other. 
//
//
// 1. Non overlapping.
//
//     [1,.,.,4]                  or                  [7,.,.,10]   
//                [7,.,.,10]              [1,.,.,4] 
//
// 2. First interval ends after second interval begins.
//
//     [1,.,.,4]
//         [3,.,.,6]
//
// 3. First interval starts after second interval begins.
//
//             [1,.,.,4]
//         [3,.,.,6]
//
// 4. One interval contains the other interval entirely.
//
//     [1,.,.,.,.,.,.,.,9]       or        [3,.,.,6]
//         [3,.,.,6]                   [1,.,.,.,.,.,.,.,9]
//
//
//
// If we sort by starting point, we can tell if intervals, we will only have:
//
//
// 1. Non overlapping
//
//     [1,.,.,4]             
//                [7,.,.,10]     
//
// 2. First interval ends after second interval begins.
//
//     [1,.,.,4]
//         [3,.,.,6]
//
// 3. Interval 1 contains interval 2
//
//     [1,.,.,.,.,.,.,.,9]
//         [3,.,.,6] 
//
//
// Notice that IFF there is an overlap (case 2 and 3), the start of interval
// 2 is LESS than the end of interval 1.
//
// This is a key property used to solve almost all interval problems.
