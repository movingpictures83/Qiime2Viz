# Qiime2Viz
# Language: C++
# Input: TXT
# Output: QZV
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Qiime 2 2020.11, Conda 4.9.2

Qiime 2 (Bolyan et al, 2019) visualization engine.

The plugin accepts as input a TXT file of keyword-value pairs and generates its output in Qiime 2 Visualization format (the QZV file).

Like Qiime 2, the plugin offers multiple types of visualization and accepts a first and second argument corresponding to the visualization type (keyword op1 and op2 in the input TXT file).

Examples of each supported type can be found in example/parameters*.viz.txt.

Depending on the values of op1 and op2, different keywords will be supported.
