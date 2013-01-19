<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Perl-compatible regular expressions</title>
<meta name="generator" content="DocBook XSL Stylesheets V1.75.2">
<link rel="home" href="index.html" title="GLib Reference Manual">
<link rel="up" href="glib-utilities.html" title="GLib Utilities">
<link rel="prev" href="glib-Glob-style-pattern-matching.html" title="Glob-style pattern matching">
<link rel="next" href="glib-Simple-XML-Subset-Parser.html" title="Simple XML Subset Parser">
<meta name="generator" content="GTK-Doc V1.15.1 (XML mode)">
<link rel="stylesheet" href="style.css" type="text/css">
</head>
<body bgcolor="white" text="black" link="#0000FF" vlink="#840084" alink="#0000FF">
<table class="navigation" id="top" width="100%" summary="Navigation header" cellpadding="2" cellspacing="2">
<tr valign="middle">
<td><a accesskey="p" href="glib-Glob-style-pattern-matching.html"><img src="left.png" width="24" height="24" border="0" alt="Prev"></a></td>
<td><a accesskey="u" href="glib-utilities.html"><img src="up.png" width="24" height="24" border="0" alt="Up"></a></td>
<td><a accesskey="h" href="index.html"><img src="home.png" width="24" height="24" border="0" alt="Home"></a></td>
<th width="100%" align="center">GLib Reference Manual</th>
<td><a accesskey="n" href="glib-Simple-XML-Subset-Parser.html"><img src="right.png" width="24" height="24" border="0" alt="Next"></a></td>
</tr>
<tr><td colspan="5" class="shortcuts">
<a href="#glib-Perl-compatible-regular-expressions.synopsis" class="shortcut">Top</a>
                   | 
                  <a href="#glib-Perl-compatible-regular-expressions.description" class="shortcut">Description</a>
</td></tr>
</table>
<div class="refentry">
<a name="glib-Perl-compatible-regular-expressions"></a><div class="titlepage"></div>
<div class="refnamediv"><table width="100%"><tr>
<td valign="top">
<h2><span class="refentrytitle"><a name="glib-Perl-compatible-regular-expressions.top_of_page"></a>Perl-compatible regular expressions</span></h2>
<p>Perl-compatible regular expressions — matches strings against regular expressions</p>
</td>
<td valign="top" align="right"></td>
</tr></table></div>
<div class="refsynopsisdiv">
<a name="glib-Perl-compatible-regular-expressions.synopsis"></a><h2>Synopsis</h2>
<pre class="synopsis">
#include &lt;glib.h&gt;

enum                <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexError" title="enum GRegexError">GRegexError</a>;
#define             <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-ERROR:CAPS" title="G_REGEX_ERROR">G_REGEX_ERROR</a>
enum                <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags">GRegexCompileFlags</a>;
enum                <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags">GRegexMatchFlags</a>;
                    <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex">GRegex</a>;
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            (<a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexEvalCallback" title="GRegexEvalCallback ()">*GRegexEvalCallback</a>)               (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Strings.html#GString" title="GString"><span class="type">GString</span></a> *result</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gpointer" title="gpointer"><span class="type">gpointer</span></a> user_data</code></em>);
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="returnvalue">GRegex</span></a> *            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()">g_regex_new</a>                         (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *pattern</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="type">GRegexCompileFlags</span></a> compile_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="returnvalue">GRegex</span></a> *            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-ref" title="g_regex_ref ()">g_regex_ref</a>                         (<em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);
<span class="returnvalue">void</span>                <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-unref" title="g_regex_unref ()">g_regex_unref</a>                       (<em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);
const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *       <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-get-pattern" title="g_regex_get_pattern ()">g_regex_get_pattern</a>                 (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);
<a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="returnvalue">gint</span></a>                <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-get-max-backref" title="g_regex_get_max_backref ()">g_regex_get_max_backref</a>             (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);
<a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="returnvalue">gint</span></a>                <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-get-capture-count" title="g_regex_get_capture_count ()">g_regex_get_capture_count</a>           (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);
<a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="returnvalue">gint</span></a>                <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-get-string-number" title="g_regex_get_string_number ()">g_regex_get_string_number</a>           (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *name</code></em>);
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="returnvalue">GRegexCompileFlags</span></a>  <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-get-compile-flags" title="g_regex_get_compile_flags ()">g_regex_get_compile_flags</a>           (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="returnvalue">GRegexMatchFlags</span></a>    <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-get-match-flags" title="g_regex_get_match_flags ()">g_regex_get_match_flags</a>             (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-escape-string" title="g_regex_escape_string ()">g_regex_escape_string</a>               (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> length</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-simple" title="g_regex_match_simple ()">g_regex_match_simple</a>                (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *pattern</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="type">GRegexCompileFlags</span></a> compile_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match" title="g_regex_match ()">g_regex_match</a>                       (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> **match_info</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-full" title="g_regex_match_full ()">g_regex_match_full</a>                  (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> **match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all" title="g_regex_match_all ()">g_regex_match_all</a>                   (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> **match_info</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all-full" title="g_regex_match_all_full ()">g_regex_match_all_full</a>              (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> **match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> **            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-split-simple" title="g_regex_split_simple ()">g_regex_split_simple</a>                (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *pattern</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="type">GRegexCompileFlags</span></a> compile_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> **            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-split" title="g_regex_split ()">g_regex_split</a>                       (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> **            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-split-full" title="g_regex_split_full ()">g_regex_split_full</a>                  (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> max_tokens</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace" title="g_regex_replace ()">g_regex_replace</a>                     (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *replacement</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-literal" title="g_regex_replace_literal ()">g_regex_replace_literal</a>             (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *replacement</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-eval" title="g_regex_replace_eval ()">g_regex_replace_eval</a>                (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexEvalCallback" title="GRegexEvalCallback ()"><span class="type">GRegexEvalCallback</span></a> eval</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gpointer" title="gpointer"><span class="type">gpointer</span></a> user_data</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-check-replacement" title="g_regex_check_replacement ()">g_regex_check_replacement</a>           (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *replacement</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="type">gboolean</span></a> *has_references</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
                    <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo">GMatchInfo</a>;
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="returnvalue">GRegex</span></a> *            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-get-regex" title="g_match_info_get_regex ()">g_match_info_get_regex</a>              (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);
const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *       <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-get-string" title="g_match_info_get_string ()">g_match_info_get_string</a>             (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);
<span class="returnvalue">void</span>                <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-free" title="g_match_info_free ()">g_match_info_free</a>                   (<em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-matches" title="g_match_info_matches ()">g_match_info_matches</a>                (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-next" title="g_match_info_next ()">g_match_info_next</a>                   (<em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="returnvalue">gint</span></a>                <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-get-match-count" title="g_match_info_get_match_count ()">g_match_info_get_match_count</a>        (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-is-partial-match" title="g_match_info_is_partial_match ()">g_match_info_is_partial_match</a>       (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-expand-references" title="g_match_info_expand_references ()">g_match_info_expand_references</a>      (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string_to_expand</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch" title="g_match_info_fetch ()">g_match_info_fetch</a>                  (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> match_num</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch-pos" title="g_match_info_fetch_pos ()">g_match_info_fetch_pos</a>              (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> match_num</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> *start_pos</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> *end_pos</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch-named" title="g_match_info_fetch_named ()">g_match_info_fetch_named</a>            (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *name</code></em>);
<a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch-named-pos" title="g_match_info_fetch_named_pos ()">g_match_info_fetch_named_pos</a>        (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *name</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> *start_pos</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> *end_pos</code></em>);
<a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> **            <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch-all" title="g_match_info_fetch_all ()">g_match_info_fetch_all</a>              (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);
</pre>
</div>
<div class="refsect1">
<a name="glib-Perl-compatible-regular-expressions.description"></a><h2>Description</h2>
<p>
The <code class="function">g_regex_*()</code> functions implement regular
expression pattern matching using syntax and semantics similar to
Perl regular expression.
</p>
<p>
Some functions accept a <em class="parameter"><code>start_position</code></em> argument, setting it differs
from just passing over a shortened string and setting <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NOTBOL:CAPS"><span class="type">G_REGEX_MATCH_NOTBOL</span></a>
in the case of a pattern that begins with any kind of lookbehind assertion.
For example, consider the pattern "\Biss\B" which finds occurrences of "iss"
in the middle of words. ("\B" matches only if the current position in the
subject is not a word boundary.) When applied to the string "Mississipi"
from the fourth byte, namely "issipi", it does not match, because "\B" is
always false at the start of the subject, which is deemed to be a word
boundary. However, if the entire string is passed , but with
<em class="parameter"><code>start_position</code></em> set to 4, it finds the second occurrence of "iss" because
it is able to look behind the starting point to discover that it is
preceded by a letter.
</p>
<p>
Note that, unless you set the <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-RAW:CAPS"><span class="type">G_REGEX_RAW</span></a> flag, all the strings passed
to these functions must be encoded in UTF-8. The lengths and the positions
inside the strings are in bytes and not in characters, so, for instance,
"\xc3\xa0" (i.e. "à") is two bytes long but it is treated as a
single character. If you set <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-RAW:CAPS"><span class="type">G_REGEX_RAW</span></a> the strings can be non-valid
UTF-8 strings and a byte is treated as a character, so "\xc3\xa0" is two
bytes and two characters long.
</p>
<p>
When matching a pattern, "\n" matches only against a "\n" character in
the string, and "\r" matches only a "\r" character. To match any newline
sequence use "\R". This particular group matches either the two-character
sequence CR + LF ("\r\n"), or one of the single characters LF (linefeed,
U+000A, "\n"), VT vertical tab, U+000B, "\v"), FF (formfeed, U+000C, "\f"),
CR (carriage return, U+000D, "\r"), NEL (next line, U+0085), LS (line
separator, U+2028), or PS (paragraph separator, U+2029).
</p>
<p>
The behaviour of the dot, circumflex, and dollar metacharacters are
affected by newline characters, the default is to recognize any newline
character (the same characters recognized by "\R"). This can be changed
with <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-NEWLINE-CR:CAPS"><span class="type">G_REGEX_NEWLINE_CR</span></a>, <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-NEWLINE-LF:CAPS"><span class="type">G_REGEX_NEWLINE_LF</span></a> and <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-NEWLINE-CRLF:CAPS"><span class="type">G_REGEX_NEWLINE_CRLF</span></a>
compile options, and with <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NEWLINE-ANY:CAPS"><span class="type">G_REGEX_MATCH_NEWLINE_ANY</span></a>,
<a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NEWLINE-CR:CAPS"><span class="type">G_REGEX_MATCH_NEWLINE_CR</span></a>, <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NEWLINE-LF:CAPS"><span class="type">G_REGEX_MATCH_NEWLINE_LF</span></a> and
<a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NEWLINE-CRLF:CAPS"><span class="type">G_REGEX_MATCH_NEWLINE_CRLF</span></a> match options. These settings are also
relevant when compiling a pattern if <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-EXTENDED:CAPS"><span class="type">G_REGEX_EXTENDED</span></a> is set, and an
unescaped "#" outside a character class is encountered. This indicates
a comment that lasts until after the next newline.
</p>
<p>
Creating and manipulating the same <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure from different
threads is not a problem as <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> does not modify its internal
state between creation and destruction, on the other hand <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a>
is not threadsafe.
</p>
<p>
The regular expressions low-level functionalities are obtained through
the excellent <a class="ulink" href="http://www.pcre.org/" target="_top">PCRE</a> library
written by Philip Hazel.
</p>
</div>
<div class="refsect1">
<a name="glib-Perl-compatible-regular-expressions.details"></a><h2>Details</h2>
<div class="refsect2">
<a name="GRegexError"></a><h3>enum GRegexError</h3>
<pre class="programlisting">typedef enum
{
  G_REGEX_ERROR_COMPILE,
  G_REGEX_ERROR_OPTIMIZE,
  G_REGEX_ERROR_REPLACE,
  G_REGEX_ERROR_MATCH,
  G_REGEX_ERROR_INTERNAL,

  /* These are the error codes from PCRE + 100 */
  G_REGEX_ERROR_STRAY_BACKSLASH = 101,
  G_REGEX_ERROR_MISSING_CONTROL_CHAR = 102,
  G_REGEX_ERROR_UNRECOGNIZED_ESCAPE = 103,
  G_REGEX_ERROR_QUANTIFIERS_OUT_OF_ORDER = 104,
  G_REGEX_ERROR_QUANTIFIER_TOO_BIG = 105,
  G_REGEX_ERROR_UNTERMINATED_CHARACTER_CLASS = 106,
  G_REGEX_ERROR_INVALID_ESCAPE_IN_CHARACTER_CLASS = 107,
  G_REGEX_ERROR_RANGE_OUT_OF_ORDER = 108,
  G_REGEX_ERROR_NOTHING_TO_REPEAT = 109,
  G_REGEX_ERROR_UNRECOGNIZED_CHARACTER = 112,
  G_REGEX_ERROR_POSIX_NAMED_CLASS_OUTSIDE_CLASS = 113,
  G_REGEX_ERROR_UNMATCHED_PARENTHESIS = 114,
  G_REGEX_ERROR_INEXISTENT_SUBPATTERN_REFERENCE = 115,
  G_REGEX_ERROR_UNTERMINATED_COMMENT = 118,
  G_REGEX_ERROR_EXPRESSION_TOO_LARGE = 120,
  G_REGEX_ERROR_MEMORY_ERROR = 121,
  G_REGEX_ERROR_VARIABLE_LENGTH_LOOKBEHIND = 125,
  G_REGEX_ERROR_MALFORMED_CONDITION = 126,
  G_REGEX_ERROR_TOO_MANY_CONDITIONAL_BRANCHES = 127,
  G_REGEX_ERROR_ASSERTION_EXPECTED = 128,
  G_REGEX_ERROR_UNKNOWN_POSIX_CLASS_NAME = 130,
  G_REGEX_ERROR_POSIX_COLLATING_ELEMENTS_NOT_SUPPORTED = 131,
  G_REGEX_ERROR_HEX_CODE_TOO_LARGE = 134,
  G_REGEX_ERROR_INVALID_CONDITION = 135,
  G_REGEX_ERROR_SINGLE_BYTE_MATCH_IN_LOOKBEHIND = 136,
  G_REGEX_ERROR_INFINITE_LOOP = 140,
  G_REGEX_ERROR_MISSING_SUBPATTERN_NAME_TERMINATOR = 142,
  G_REGEX_ERROR_DUPLICATE_SUBPATTERN_NAME = 143,
  G_REGEX_ERROR_MALFORMED_PROPERTY = 146,
  G_REGEX_ERROR_UNKNOWN_PROPERTY = 147,
  G_REGEX_ERROR_SUBPATTERN_NAME_TOO_LONG = 148,
  G_REGEX_ERROR_TOO_MANY_SUBPATTERNS = 149,
  G_REGEX_ERROR_INVALID_OCTAL_VALUE = 151,
  G_REGEX_ERROR_TOO_MANY_BRANCHES_IN_DEFINE = 154,
  G_REGEX_ERROR_DEFINE_REPETION = 155,
  G_REGEX_ERROR_INCONSISTENT_NEWLINE_OPTIONS = 156,
  G_REGEX_ERROR_MISSING_BACK_REFERENCE = 157
} GRegexError;
</pre>
<p>
Error codes returned by regular expressions functions.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><a name="G-REGEX-ERROR-COMPILE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_COMPILE</code></span></p></td>
<td>Compilation of the regular expression failed.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-OPTIMIZE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_OPTIMIZE</code></span></p></td>
<td>Optimization of the regular expression failed.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-REPLACE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_REPLACE</code></span></p></td>
<td>Replacement failed due to an ill-formed replacement
    string.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-MATCH:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_MATCH</code></span></p></td>
<td>The match process failed.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-INTERNAL:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_INTERNAL</code></span></p></td>
<td>Internal error of the regular expression engine.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-STRAY-BACKSLASH:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_STRAY_BACKSLASH</code></span></p></td>
<td>"\\" at end of pattern. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-MISSING-CONTROL-CHAR:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_MISSING_CONTROL_CHAR</code></span></p></td>
<td>"\\c" at end of pattern. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-UNRECOGNIZED-ESCAPE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_UNRECOGNIZED_ESCAPE</code></span></p></td>
<td>Unrecognized character follows "\\".
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-QUANTIFIERS-OUT-OF-ORDER:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_QUANTIFIERS_OUT_OF_ORDER</code></span></p></td>
<td>Numbers out of order in "{}"
    quantifier. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-QUANTIFIER-TOO-BIG:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_QUANTIFIER_TOO_BIG</code></span></p></td>
<td>Number too big in "{}" quantifier.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-UNTERMINATED-CHARACTER-CLASS:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_UNTERMINATED_CHARACTER_CLASS</code></span></p></td>
<td>Missing terminating "]" for
    character class. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-INVALID-ESCAPE-IN-CHARACTER-CLASS:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_INVALID_ESCAPE_IN_CHARACTER_CLASS</code></span></p></td>
<td>Invalid escape sequence
    in character class. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-RANGE-OUT-OF-ORDER:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_RANGE_OUT_OF_ORDER</code></span></p></td>
<td>Range out of order in character class.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-NOTHING-TO-REPEAT:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_NOTHING_TO_REPEAT</code></span></p></td>
<td>Nothing to repeat. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-UNRECOGNIZED-CHARACTER:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_UNRECOGNIZED_CHARACTER</code></span></p></td>
<td>Unrecognized character after "(?",
    "(?&lt;" or "(?P". Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-POSIX-NAMED-CLASS-OUTSIDE-CLASS:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_POSIX_NAMED_CLASS_OUTSIDE_CLASS</code></span></p></td>
<td>POSIX named classes are
    supported only within a class. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-UNMATCHED-PARENTHESIS:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_UNMATCHED_PARENTHESIS</code></span></p></td>
<td>Missing terminating ")" or ")"
    without opening "(". Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-INEXISTENT-SUBPATTERN-REFERENCE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_INEXISTENT_SUBPATTERN_REFERENCE</code></span></p></td>
<td>Reference to non-existent
    subpattern. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-UNTERMINATED-COMMENT:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_UNTERMINATED_COMMENT</code></span></p></td>
<td>Missing terminating ")" after comment.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-EXPRESSION-TOO-LARGE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_EXPRESSION_TOO_LARGE</code></span></p></td>
<td>Regular expression too large.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-MEMORY-ERROR:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_MEMORY_ERROR</code></span></p></td>
<td>Failed to get memory. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-VARIABLE-LENGTH-LOOKBEHIND:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_VARIABLE_LENGTH_LOOKBEHIND</code></span></p></td>
<td>Lookbehind assertion is not
    fixed length. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-MALFORMED-CONDITION:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_MALFORMED_CONDITION</code></span></p></td>
<td>Malformed number or name after "(?(".
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-TOO-MANY-CONDITIONAL-BRANCHES:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_TOO_MANY_CONDITIONAL_BRANCHES</code></span></p></td>
<td>Conditional group contains
    more than two branches. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-ASSERTION-EXPECTED:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_ASSERTION_EXPECTED</code></span></p></td>
<td>Assertion expected after "(?(".
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-UNKNOWN-POSIX-CLASS-NAME:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_UNKNOWN_POSIX_CLASS_NAME</code></span></p></td>
<td>Unknown POSIX class name.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-POSIX-COLLATING-ELEMENTS-NOT-SUPPORTED:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_POSIX_COLLATING_ELEMENTS_NOT_SUPPORTED</code></span></p></td>
<td>POSIX collating
    elements are not supported. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-HEX-CODE-TOO-LARGE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_HEX_CODE_TOO_LARGE</code></span></p></td>
<td>Character value in "\\x{...}" sequence
    is too large. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-INVALID-CONDITION:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_INVALID_CONDITION</code></span></p></td>
<td>Invalid condition "(?(0)". Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-SINGLE-BYTE-MATCH-IN-LOOKBEHIND:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_SINGLE_BYTE_MATCH_IN_LOOKBEHIND</code></span></p></td>
<td>\\C not allowed in
    lookbehind assertion. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-INFINITE-LOOP:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_INFINITE_LOOP</code></span></p></td>
<td>Recursive call could loop indefinitely.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-MISSING-SUBPATTERN-NAME-TERMINATOR:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_MISSING_SUBPATTERN_NAME_TERMINATOR</code></span></p></td>
<td>Missing terminator
    in subpattern name. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-DUPLICATE-SUBPATTERN-NAME:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_DUPLICATE_SUBPATTERN_NAME</code></span></p></td>
<td>Two named subpatterns have
    the same name. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-MALFORMED-PROPERTY:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_MALFORMED_PROPERTY</code></span></p></td>
<td>Malformed "\\P" or "\\p" sequence.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-UNKNOWN-PROPERTY:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_UNKNOWN_PROPERTY</code></span></p></td>
<td>Unknown property name after "\\P" or
    "\\p". Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-SUBPATTERN-NAME-TOO-LONG:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_SUBPATTERN_NAME_TOO_LONG</code></span></p></td>
<td>Subpattern name is too long
    (maximum 32 characters). Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-TOO-MANY-SUBPATTERNS:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_TOO_MANY_SUBPATTERNS</code></span></p></td>
<td>Too many named subpatterns (maximum
    10,000). Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-INVALID-OCTAL-VALUE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_INVALID_OCTAL_VALUE</code></span></p></td>
<td>Octal value is greater than "\\377".
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-TOO-MANY-BRANCHES-IN-DEFINE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_TOO_MANY_BRANCHES_IN_DEFINE</code></span></p></td>
<td>"DEFINE" group contains more
    than one branch. Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-DEFINE-REPETION:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_DEFINE_REPETION</code></span></p></td>
<td>Repeating a "DEFINE" group is not allowed.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-INCONSISTENT-NEWLINE-OPTIONS:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_INCONSISTENT_NEWLINE_OPTIONS</code></span></p></td>
<td>Inconsistent newline options.
    Since 2.16
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ERROR-MISSING-BACK-REFERENCE:CAPS"></a><span class="term"><code class="literal">G_REGEX_ERROR_MISSING_BACK_REFERENCE</code></span></p></td>
<td>"\\g" is not followed by a braced
    name or an optionally braced non-zero number. Since 2.16
</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="G-REGEX-ERROR:CAPS"></a><h3>G_REGEX_ERROR</h3>
<pre class="programlisting">#define G_REGEX_ERROR g_regex_error_quark ()
</pre>
<p>
Error domain for regular expressions. Errors in this domain will be
from the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexError" title="enum GRegexError"><span class="type">GRegexError</span></a> enumeration. See <a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> for information on
error domains.
</p>
<p class="since">Since </p>
</div>
<hr>
<div class="refsect2">
<a name="GRegexCompileFlags"></a><h3>enum GRegexCompileFlags</h3>
<pre class="programlisting">typedef enum
{
  G_REGEX_CASELESS          = 1 &lt;&lt; 0,
  G_REGEX_MULTILINE         = 1 &lt;&lt; 1,
  G_REGEX_DOTALL            = 1 &lt;&lt; 2,
  G_REGEX_EXTENDED          = 1 &lt;&lt; 3,
  G_REGEX_ANCHORED          = 1 &lt;&lt; 4,
  G_REGEX_DOLLAR_ENDONLY    = 1 &lt;&lt; 5,
  G_REGEX_UNGREEDY          = 1 &lt;&lt; 9,
  G_REGEX_RAW               = 1 &lt;&lt; 11,
  G_REGEX_NO_AUTO_CAPTURE   = 1 &lt;&lt; 12,
  G_REGEX_OPTIMIZE          = 1 &lt;&lt; 13,
  G_REGEX_DUPNAMES          = 1 &lt;&lt; 19,
  G_REGEX_NEWLINE_CR        = 1 &lt;&lt; 20,
  G_REGEX_NEWLINE_LF        = 1 &lt;&lt; 21,
  G_REGEX_NEWLINE_CRLF      = G_REGEX_NEWLINE_CR | G_REGEX_NEWLINE_LF
} GRegexCompileFlags;
</pre>
<p>
Flags specifying compile-time options.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><a name="G-REGEX-CASELESS:CAPS"></a><span class="term"><code class="literal">G_REGEX_CASELESS</code></span></p></td>
<td>Letters in the pattern match both upper- and
    lowercase letters. This option can be changed within a pattern
    by a "(?i)" option setting.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MULTILINE:CAPS"></a><span class="term"><code class="literal">G_REGEX_MULTILINE</code></span></p></td>
<td>By default, GRegex treats the strings as consisting
    of a single line of characters (even if it actually contains
    newlines). The "start of line" metacharacter ("^") matches only
    at the start of the string, while the "end of line" metacharacter
    ("$") matches only at the end of the string, or before a terminating
    newline (unless <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-DOLLAR-ENDONLY:CAPS"><span class="type">G_REGEX_DOLLAR_ENDONLY</span></a> is set). When
    <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MULTILINE:CAPS"><span class="type">G_REGEX_MULTILINE</span></a> is set, the "start of line" and "end of line"
    constructs match immediately following or immediately before any
    newline in the string, respectively, as well as at the very start
    and end. This can be changed within a pattern by a "(?m)" option
    setting.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-DOTALL:CAPS"></a><span class="term"><code class="literal">G_REGEX_DOTALL</code></span></p></td>
<td>A dot metacharater (".") in the pattern matches all
    characters, including newlines. Without it, newlines are excluded.
    This option can be changed within a pattern by a ("?s") option setting.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-EXTENDED:CAPS"></a><span class="term"><code class="literal">G_REGEX_EXTENDED</code></span></p></td>
<td>Whitespace data characters in the pattern are
    totally ignored except when escaped or inside a character class.
    Whitespace does not include the VT character (code 11). In addition,
    characters between an unescaped "#" outside a character class and
    the next newline character, inclusive, are also ignored. This can
    be changed within a pattern by a "(?x)" option setting.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-ANCHORED:CAPS"></a><span class="term"><code class="literal">G_REGEX_ANCHORED</code></span></p></td>
<td>The pattern is forced to be "anchored", that is,
    it is constrained to match only at the first matching point in the
    string that is being searched. This effect can also be achieved by
    appropriate constructs in the pattern itself such as the "^"
    metacharater.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-DOLLAR-ENDONLY:CAPS"></a><span class="term"><code class="literal">G_REGEX_DOLLAR_ENDONLY</code></span></p></td>
<td>A dollar metacharacter ("$") in the pattern
    matches only at the end of the string. Without this option, a
    dollar also matches immediately before the final character if
    it is a newline (but not before any other newlines). This option
    is ignored if <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MULTILINE:CAPS"><span class="type">G_REGEX_MULTILINE</span></a> is set.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-UNGREEDY:CAPS"></a><span class="term"><code class="literal">G_REGEX_UNGREEDY</code></span></p></td>
<td>Inverts the "greediness" of the quantifiers so that
    they are not greedy by default, but become greedy if followed by "?".
    It can also be set by a "(?U)" option setting within the pattern.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-RAW:CAPS"></a><span class="term"><code class="literal">G_REGEX_RAW</code></span></p></td>
<td>Usually strings must be valid UTF-8 strings, using this
    flag they are considered as a raw sequence of bytes.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-NO-AUTO-CAPTURE:CAPS"></a><span class="term"><code class="literal">G_REGEX_NO_AUTO_CAPTURE</code></span></p></td>
<td>Disables the use of numbered capturing
    parentheses in the pattern. Any opening parenthesis that is not
    followed by "?" behaves as if it were followed by "?:" but named
    parentheses can still be used for capturing (and they acquire numbers
    in the usual way).
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-OPTIMIZE:CAPS"></a><span class="term"><code class="literal">G_REGEX_OPTIMIZE</code></span></p></td>
<td>Optimize the regular expression. If the pattern will
    be used many times, then it may be worth the effort to optimize it
    to improve the speed of matches.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-DUPNAMES:CAPS"></a><span class="term"><code class="literal">G_REGEX_DUPNAMES</code></span></p></td>
<td>Names used to identify capturing subpatterns need not
    be unique. This can be helpful for certain types of pattern when it
    is known that only one instance of the named subpattern can ever be
    matched.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-NEWLINE-CR:CAPS"></a><span class="term"><code class="literal">G_REGEX_NEWLINE_CR</code></span></p></td>
<td>Usually any newline character is recognized, if this
    option is set, the only recognized newline character is '\r'.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-NEWLINE-LF:CAPS"></a><span class="term"><code class="literal">G_REGEX_NEWLINE_LF</code></span></p></td>
<td>Usually any newline character is recognized, if this
    option is set, the only recognized newline character is '\n'.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-NEWLINE-CRLF:CAPS"></a><span class="term"><code class="literal">G_REGEX_NEWLINE_CRLF</code></span></p></td>
<td>Usually any newline character is recognized, if this
    option is set, the only recognized newline character sequence is '\r\n'.
</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="GRegexMatchFlags"></a><h3>enum GRegexMatchFlags</h3>
<pre class="programlisting">typedef enum
{
  G_REGEX_MATCH_ANCHORED      = 1 &lt;&lt; 4,
  G_REGEX_MATCH_NOTBOL        = 1 &lt;&lt; 7,
  G_REGEX_MATCH_NOTEOL        = 1 &lt;&lt; 8,
  G_REGEX_MATCH_NOTEMPTY      = 1 &lt;&lt; 10,
  G_REGEX_MATCH_PARTIAL       = 1 &lt;&lt; 15,
  G_REGEX_MATCH_NEWLINE_CR    = 1 &lt;&lt; 20,
  G_REGEX_MATCH_NEWLINE_LF    = 1 &lt;&lt; 21,
  G_REGEX_MATCH_NEWLINE_CRLF  = G_REGEX_MATCH_NEWLINE_CR | G_REGEX_MATCH_NEWLINE_LF,
  G_REGEX_MATCH_NEWLINE_ANY   = 1 &lt;&lt; 22
} GRegexMatchFlags;
</pre>
<p>
Flags specifying match-time options.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><a name="G-REGEX-MATCH-ANCHORED:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_ANCHORED</code></span></p></td>
<td>The pattern is forced to be "anchored", that is,
    it is constrained to match only at the first matching point in the
    string that is being searched. This effect can also be achieved by
    appropriate constructs in the pattern itself such as the "^"
    metacharater.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MATCH-NOTBOL:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_NOTBOL</code></span></p></td>
<td>Specifies that first character of the string is
    not the beginning of a line, so the circumflex metacharacter should
    not match before it. Setting this without <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MULTILINE:CAPS"><span class="type">G_REGEX_MULTILINE</span></a> (at
    compile time) causes circumflex never to match. This option affects
    only the behaviour of the circumflex metacharacter, it does not
    affect "\A".
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MATCH-NOTEOL:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_NOTEOL</code></span></p></td>
<td>Specifies that the end of the subject string is
    not the end of a line, so the dollar metacharacter should not match
    it nor (except in multiline mode) a newline immediately before it.
    Setting this without <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MULTILINE:CAPS"><span class="type">G_REGEX_MULTILINE</span></a> (at compile time) causes
    dollar never to match. This option affects only the behaviour of
    the dollar metacharacter, it does not affect "\Z" or "\z".
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MATCH-NOTEMPTY:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_NOTEMPTY</code></span></p></td>
<td>An empty string is not considered to be a valid
    match if this option is set. If there are alternatives in the pattern,
    they are tried. If all the alternatives match the empty string, the
    entire match fails. For example, if the pattern "a?b?" is applied to
    a string not beginning with "a" or "b", it matches the empty string
    at the start of the string. With this flag set, this match is not
    valid, so GRegex searches further into the string for occurrences
    of "a" or "b".
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MATCH-PARTIAL:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_PARTIAL</code></span></p></td>
<td>Turns on the partial matching feature, for more
    documentation on partial matching see <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-is-partial-match" title="g_match_info_is_partial_match ()"><code class="function">g_match_info_is_partial_match()</code></a>.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MATCH-NEWLINE-CR:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_NEWLINE_CR</code></span></p></td>
<td>Overrides the newline definition set when
    creating a new <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>, setting the '\r' character as line terminator.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MATCH-NEWLINE-LF:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_NEWLINE_LF</code></span></p></td>
<td>Overrides the newline definition set when
    creating a new <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>, setting the '\n' character as line terminator.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MATCH-NEWLINE-CRLF:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_NEWLINE_CRLF</code></span></p></td>
<td>Overrides the newline definition set when
    creating a new <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>, setting the '\r\n' characters as line terminator.
</td>
</tr>
<tr>
<td><p><a name="G-REGEX-MATCH-NEWLINE-ANY:CAPS"></a><span class="term"><code class="literal">G_REGEX_MATCH_NEWLINE_ANY</code></span></p></td>
<td>Overrides the newline definition set when
    creating a new <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>, any newline character or character sequence
    is recognized.
</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="GRegex"></a><h3>GRegex</h3>
<pre class="programlisting">typedef struct _GRegex GRegex;</pre>
<p>
A GRegex is the "compiled" form of a regular expression pattern. This
structure is opaque and its fields cannot be accessed directly.
</p>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="GRegexEvalCallback"></a><h3>GRegexEvalCallback ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            (*GRegexEvalCallback)               (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Strings.html#GString" title="GString"><span class="type">GString</span></a> *result</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gpointer" title="gpointer"><span class="type">gpointer</span></a> user_data</code></em>);</pre>
<p>
Specifies the type of the function passed to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-eval" title="g_regex_replace_eval ()"><code class="function">g_regex_replace_eval()</code></a>.
It is called for each occurance of the pattern in the string passed
to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-eval" title="g_regex_replace_eval ()"><code class="function">g_regex_replace_eval()</code></a>, and it should append the replacement to
<em class="parameter"><code>result</code></em>.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> generated by the match.
    Use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-get-regex" title="g_match_info_get_regex ()"><code class="function">g_match_info_get_regex()</code></a> and <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-get-string" title="g_match_info_get_string ()"><code class="function">g_match_info_get_string()</code></a> if you
    need the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> or the matched string.
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>result</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Strings.html#GString" title="GString"><span class="type">GString</span></a> containing the new string
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>user_data</code></em> :</span></p></td>
<td>user data passed to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-eval" title="g_regex_replace_eval ()"><code class="function">g_regex_replace_eval()</code></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> to continue the replacement process, <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> to stop it

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-new"></a><h3>g_regex_new ()</h3>
<pre class="programlisting"><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="returnvalue">GRegex</span></a> *            g_regex_new                         (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *pattern</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="type">GRegexCompileFlags</span></a> compile_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Compiles the regular expression to an internal form, and does
the initial setup of the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>pattern</code></em> :</span></p></td>
<td>the regular expression
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>compile_options</code></em> :</span></p></td>
<td>compile options for the regular expression, or 0
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match options for the regular expression, or 0
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>return location for a <a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure. Call <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-unref" title="g_regex_unref ()"><code class="function">g_regex_unref()</code></a> when you
  are done with it

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-ref"></a><h3>g_regex_ref ()</h3>
<pre class="programlisting"><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="returnvalue">GRegex</span></a> *            g_regex_ref                         (<em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);</pre>
<p>
Increases reference count of <em class="parameter"><code>regex</code></em> by 1.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <em class="parameter"><code>regex</code></em>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-unref"></a><h3>g_regex_unref ()</h3>
<pre class="programlisting"><span class="returnvalue">void</span>                g_regex_unref                       (<em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);</pre>
<p>
Decreases reference count of <em class="parameter"><code>regex</code></em> by 1. When reference count drops
to zero, it frees all the memory associated with the regex structure.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody><tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>
</td>
</tr></tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-get-pattern"></a><h3>g_regex_get_pattern ()</h3>
<pre class="programlisting">const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *       g_regex_get_pattern                 (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);</pre>
<p>
Gets the pattern string associated with <em class="parameter"><code>regex</code></em>, i.e. a copy of
the string passed to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> the pattern of <em class="parameter"><code>regex</code></em>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-get-max-backref"></a><h3>g_regex_get_max_backref ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="returnvalue">gint</span></a>                g_regex_get_max_backref             (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);</pre>
<p>
Returns the number of the highest back reference
in the pattern, or 0 if the pattern does not contain
back references.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> the number of the highest back reference

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-get-capture-count"></a><h3>g_regex_get_capture_count ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="returnvalue">gint</span></a>                g_regex_get_capture_count           (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);</pre>
<p>
Returns the number of capturing subpatterns in the pattern.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> the number of capturing subpatterns

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-get-string-number"></a><h3>g_regex_get_string_number ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="returnvalue">gint</span></a>                g_regex_get_string_number           (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *name</code></em>);</pre>
<p>
Retrieves the number of the subexpression named <em class="parameter"><code>name</code></em>.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>name</code></em> :</span></p></td>
<td>name of the subexpression
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> The number of the subexpression or -1 if <em class="parameter"><code>name</code></em>
  does not exists

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-get-compile-flags"></a><h3>g_regex_get_compile_flags ()</h3>
<pre class="programlisting"><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="returnvalue">GRegexCompileFlags</span></a>  g_regex_get_compile_flags           (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);</pre>
<p>
Returns the compile options that <em class="parameter"><code>regex</code></em> was created with.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> flags from <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="type">GRegexCompileFlags</span></a>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.26</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-get-match-flags"></a><h3>g_regex_get_match_flags ()</h3>
<pre class="programlisting"><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="returnvalue">GRegexMatchFlags</span></a>    g_regex_get_match_flags             (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>);</pre>
<p>
Returns the match options that <em class="parameter"><code>regex</code></em> was created with.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> flags from <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.26</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-escape-string"></a><h3>g_regex_escape_string ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             g_regex_escape_string               (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> length</code></em>);</pre>
<p>
Escapes the special characters used for regular expressions
in <em class="parameter"><code>string</code></em>, for instance "a.b*c" becomes "a\.b\*c". This
function is useful to dynamically generate regular expressions.
</p>
<p>
<em class="parameter"><code>string</code></em> can contain nul characters that are replaced with "\0",
in this case remember to specify the correct length of <em class="parameter"><code>string</code></em>
in <em class="parameter"><code>length</code></em>.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td> the string to escape. <span class="annotation">[<acronym title="Parameter points to an array of items."><span class="acronym">array</span></acronym> length=length]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>length</code></em> :</span></p></td>
<td>the length of <em class="parameter"><code>string</code></em>, or -1 if <em class="parameter"><code>string</code></em> is nul-terminated
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a newly-allocated escaped string

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-match-simple"></a><h3>g_regex_match_simple ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_regex_match_simple                (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *pattern</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="type">GRegexCompileFlags</span></a> compile_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>);</pre>
<p>
Scans for a match in <em class="parameter"><code>string</code></em> for <em class="parameter"><code>pattern</code></em>.
</p>
<p>
This function is equivalent to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match" title="g_regex_match ()"><code class="function">g_regex_match()</code></a> but it does not
require to compile the pattern with <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>, avoiding some
lines of code when you need just to do a match without extracting
substrings, capture counts, and so on.
</p>
<p>
If this function is to be called on the same <em class="parameter"><code>pattern</code></em> more than
once, it's more efficient to compile the pattern once with
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a> and then use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match" title="g_regex_match ()"><code class="function">g_regex_match()</code></a>.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>pattern</code></em> :</span></p></td>
<td>the regular expression
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td>the string to scan for matches
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>compile_options</code></em> :</span></p></td>
<td>compile options for the regular expression, or 0
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match options, or 0
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> if the string matched, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-match"></a><h3>g_regex_match ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_regex_match                       (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> **match_info</code></em>);</pre>
<p>
Scans for a match in string for the pattern in <em class="parameter"><code>regex</code></em>.
The <em class="parameter"><code>match_options</code></em> are combined with the match options specified
when the <em class="parameter"><code>regex</code></em> structure was created, letting you have more
flexibility in reusing <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structures.
</p>
<p>
A <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure, used to get information on the match,
is stored in <em class="parameter"><code>match_info</code></em> if not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. Note that if <em class="parameter"><code>match_info</code></em>
is not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> then it is created even if the function returns <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a>,
i.e. you must free it regardless if regular expression actually matched.
</p>
<p>
To retrieve all the non-overlapping matches of the pattern in
string you can use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-next" title="g_match_info_next ()"><code class="function">g_match_info_next()</code></a>.
</p>
<p>
</p>
<div class="informalexample">
  <table class="listing_frame" border="0" cellpadding="0" cellspacing="0">
    <tbody>
      <tr>
        <td class="listing_lines" align="right"><pre>1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19</pre></td>
        <td class="listing_code"><pre class="programlisting"><span class="keyword">static</span><span class="normal"> </span><span class="type">void</span>
<span class="function">print_uppercase_words</span><span class="normal"> </span><span class="symbol">(</span><span class="keyword">const</span><span class="normal"> </span><span class="usertype">gchar</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">string</span><span class="symbol">)</span>
<span class="cbracket">{</span>
<span class="normal">  </span><span class="comment">/* Print all uppercase-only words. */</span>
<span class="normal">  </span><span class="usertype">GRegex</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">regex</span><span class="symbol">;</span>
<span class="normal">  </span><span class="usertype">GMatchInfo</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">match_info</span><span class="symbol">;</span>
<span class="normal">   </span>
<span class="normal">  regex </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-regex-new">g_regex_new</a></span><span class="normal"> </span><span class="symbol">(</span><span class="string">"[A-Z]+"</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> <a href="glib-Standard-Macros.html#NULL:CAPS">NULL</a></span><span class="symbol">);</span>
<span class="normal">  </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-regex-match">g_regex_match</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">regex</span><span class="symbol">,</span><span class="normal"> string</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> </span><span class="symbol">&amp;</span><span class="normal">match_info</span><span class="symbol">);</span>
<span class="normal">  </span><span class="keyword">while</span><span class="normal"> </span><span class="symbol">(</span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-matches">g_match_info_matches</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match_info</span><span class="symbol">))</span>
<span class="normal">    </span><span class="cbracket">{</span>
<span class="normal">      </span><span class="usertype">gchar</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">word </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch">g_match_info_fetch</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match_info</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">);</span>
<span class="normal">      </span><span class="function"><a href="glib-Warnings-and-Assertions.html#g-print">g_print</a></span><span class="normal"> </span><span class="symbol">(</span><span class="string">"Found: %s</span><span class="specialchar">\n</span><span class="string">"</span><span class="symbol">,</span><span class="normal"> word</span><span class="symbol">);</span>
<span class="normal">      </span><span class="function"><a href="glib-Memory-Allocation.html#g-free">g_free</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">word</span><span class="symbol">);</span>
<span class="normal">      </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-next">g_match_info_next</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match_info</span><span class="symbol">,</span><span class="normal"> <a href="glib-Standard-Macros.html#NULL:CAPS">NULL</a></span><span class="symbol">);</span>
<span class="normal">    </span><span class="cbracket">}</span>
<span class="normal">  </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-free">g_match_info_free</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match_info</span><span class="symbol">);</span>
<span class="normal">  </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-regex-unref">g_regex_unref</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">regex</span><span class="symbol">);</span>
<span class="cbracket">}</span></pre></td>
      </tr>
    </tbody>
  </table>
</div>

<p>
</p>
<p>
<em class="parameter"><code>string</code></em> is not copied and is used in <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> internally. If
you use any <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> method (except <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-free" title="g_match_info_free ()"><code class="function">g_match_info_free()</code></a>) after
freeing or modifying <em class="parameter"><code>string</code></em> then the behaviour is undefined.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure from <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td>the string to scan for matches
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match options
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td> pointer to location where to store
    the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a>, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> if you do not need it. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> is the string matched, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-match-full"></a><h3>g_regex_match_full ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_regex_match_full                  (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> **match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Scans for a match in string for the pattern in <em class="parameter"><code>regex</code></em>.
The <em class="parameter"><code>match_options</code></em> are combined with the match options specified
when the <em class="parameter"><code>regex</code></em> structure was created, letting you have more
flexibility in reusing <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structures.
</p>
<p>
Setting <em class="parameter"><code>start_position</code></em> differs from just passing over a shortened
string and setting <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NOTBOL:CAPS"><span class="type">G_REGEX_MATCH_NOTBOL</span></a> in the case of a pattern
that begins with any kind of lookbehind assertion, such as "\b".
</p>
<p>
A <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure, used to get information on the match, is
stored in <em class="parameter"><code>match_info</code></em> if not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. Note that if <em class="parameter"><code>match_info</code></em> is
not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> then it is created even if the function returns <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a>,
i.e. you must free it regardless if regular expression actually
matched.
</p>
<p>
<em class="parameter"><code>string</code></em> is not copied and is used in <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> internally. If
you use any <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> method (except <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-free" title="g_match_info_free ()"><code class="function">g_match_info_free()</code></a>) after
freeing or modifying <em class="parameter"><code>string</code></em> then the behaviour is undefined.
</p>
<p>
To retrieve all the non-overlapping matches of the pattern in
string you can use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-next" title="g_match_info_next ()"><code class="function">g_match_info_next()</code></a>.
</p>
<p>
</p>
<div class="informalexample">
  <table class="listing_frame" border="0" cellpadding="0" cellspacing="0">
    <tbody>
      <tr>
        <td class="listing_lines" align="right"><pre>1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25</pre></td>
        <td class="listing_code"><pre class="programlisting"><span class="keyword">static</span><span class="normal"> </span><span class="type">void</span>
<span class="function">print_uppercase_words</span><span class="normal"> </span><span class="symbol">(</span><span class="keyword">const</span><span class="normal"> </span><span class="usertype">gchar</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">string</span><span class="symbol">)</span>
<span class="cbracket">{</span>
<span class="normal">  </span><span class="comment">/* Print all uppercase-only words. */</span>
<span class="normal">  </span><span class="usertype">GRegex</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">regex</span><span class="symbol">;</span>
<span class="normal">  </span><span class="usertype">GMatchInfo</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">match_info</span><span class="symbol">;</span>
<span class="normal">  </span><span class="usertype">GError</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">error </span><span class="symbol">=</span><span class="normal"> <a href="glib-Standard-Macros.html#NULL:CAPS">NULL</a></span><span class="symbol">;</span>
<span class="normal">   </span>
<span class="normal">  regex </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-regex-new">g_regex_new</a></span><span class="normal"> </span><span class="symbol">(</span><span class="string">"[A-Z]+"</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> <a href="glib-Standard-Macros.html#NULL:CAPS">NULL</a></span><span class="symbol">);</span>
<span class="normal">  </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-regex-match-full">g_regex_match_full</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">regex</span><span class="symbol">,</span><span class="normal"> string</span><span class="symbol">,</span><span class="normal"> </span><span class="symbol">-</span><span class="number">1</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> </span><span class="symbol">&amp;</span><span class="normal">match_info</span><span class="symbol">,</span><span class="normal"> </span><span class="symbol">&amp;</span><span class="normal">error</span><span class="symbol">);</span>
<span class="normal">  </span><span class="keyword">while</span><span class="normal"> </span><span class="symbol">(</span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-matches">g_match_info_matches</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match_info</span><span class="symbol">))</span>
<span class="normal">    </span><span class="cbracket">{</span>
<span class="normal">      </span><span class="usertype">gchar</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">word </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch">g_match_info_fetch</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match_info</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">);</span>
<span class="normal">      </span><span class="function"><a href="glib-Warnings-and-Assertions.html#g-print">g_print</a></span><span class="normal"> </span><span class="symbol">(</span><span class="string">"Found: %s</span><span class="specialchar">\n</span><span class="string">"</span><span class="symbol">,</span><span class="normal"> word</span><span class="symbol">);</span>
<span class="normal">      </span><span class="function"><a href="glib-Memory-Allocation.html#g-free">g_free</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">word</span><span class="symbol">);</span>
<span class="normal">      </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-next">g_match_info_next</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match_info</span><span class="symbol">,</span><span class="normal"> </span><span class="symbol">&amp;</span><span class="normal">error</span><span class="symbol">);</span>
<span class="normal">    </span><span class="cbracket">}</span>
<span class="normal">  </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-free">g_match_info_free</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match_info</span><span class="symbol">);</span>
<span class="normal">  </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-regex-unref">g_regex_unref</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">regex</span><span class="symbol">);</span>
<span class="normal">  </span><span class="keyword">if</span><span class="normal"> </span><span class="symbol">(</span><span class="normal">error </span><span class="symbol">!=</span><span class="normal"> <a href="glib-Standard-Macros.html#NULL:CAPS">NULL</a></span><span class="symbol">)</span>
<span class="normal">    </span><span class="cbracket">{</span>
<span class="normal">      </span><span class="function"><a href="glib-Warnings-and-Assertions.html#g-printerr">g_printerr</a></span><span class="normal"> </span><span class="symbol">(</span><span class="string">"Error while matching: %s</span><span class="specialchar">\n</span><span class="string">"</span><span class="symbol">,</span><span class="normal"> error</span><span class="symbol">-&gt;</span><span class="normal">message</span><span class="symbol">);</span>
<span class="normal">      </span><span class="function"><a href="glib-Error-Reporting.html#g-error-free">g_error_free</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">error</span><span class="symbol">);</span>
<span class="normal">    </span><span class="cbracket">}</span>
<span class="cbracket">}</span></pre></td>
      </tr>
    </tbody>
  </table>
</div>

<p>
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure from <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td> the string to scan for matches. <span class="annotation">[<acronym title="Parameter points to an array of items."><span class="acronym">array</span></acronym> length=string_len]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string_len</code></em> :</span></p></td>
<td>the length of <em class="parameter"><code>string</code></em>, or -1 if <em class="parameter"><code>string</code></em> is nul-terminated
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>start_position</code></em> :</span></p></td>
<td>starting index of the string to match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match options
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td> pointer to location where to store
    the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a>, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> if you do not need it. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>location to store the error occuring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> to ignore errors
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> is the string matched, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-match-all"></a><h3>g_regex_match_all ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_regex_match_all                   (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> **match_info</code></em>);</pre>
<p>
Using the standard algorithm for regular expression matching only
the longest match in the string is retrieved. This function uses
a different algorithm so it can retrieve all the possible matches.
For more documentation see <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all-full" title="g_regex_match_all_full ()"><code class="function">g_regex_match_all_full()</code></a>.
</p>
<p>
A <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure, used to get information on the match, is
stored in <em class="parameter"><code>match_info</code></em> if not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. Note that if <em class="parameter"><code>match_info</code></em> is
not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> then it is created even if the function returns <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a>,
i.e. you must free it regardless if regular expression actually
matched.
</p>
<p>
<em class="parameter"><code>string</code></em> is not copied and is used in <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> internally. If
you use any <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> method (except <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-free" title="g_match_info_free ()"><code class="function">g_match_info_free()</code></a>) after
freeing or modifying <em class="parameter"><code>string</code></em> then the behaviour is undefined.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure from <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td>the string to scan for matches
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match options
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td> pointer to location where to store
    the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a>, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> if you do not need it. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> is the string matched, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-match-all-full"></a><h3>g_regex_match_all_full ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_regex_match_all_full              (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> **match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Using the standard algorithm for regular expression matching only
the longest match in the string is retrieved, it is not possibile
to obtain all the available matches. For instance matching
"&lt;a&gt; &lt;b&gt; &lt;c&gt;" against the pattern "&lt;.*&gt;"
you get "&lt;a&gt; &lt;b&gt; &lt;c&gt;".
</p>
<p>
This function uses a different algorithm (called DFA, i.e. deterministic
finite automaton), so it can retrieve all the possible matches, all
starting at the same point in the string. For instance matching
"&lt;a&gt; &lt;b&gt; &lt;c&gt;" against the pattern "&lt;.*&gt;"
you would obtain three matches: "&lt;a&gt; &lt;b&gt; &lt;c&gt;",
"&lt;a&gt; &lt;b&gt;" and "&lt;a&gt;".
</p>
<p>
The number of matched strings is retrieved using
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-get-match-count" title="g_match_info_get_match_count ()"><code class="function">g_match_info_get_match_count()</code></a>. To obtain the matched strings and
their position you can use, respectively, <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch" title="g_match_info_fetch ()"><code class="function">g_match_info_fetch()</code></a> and
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch-pos" title="g_match_info_fetch_pos ()"><code class="function">g_match_info_fetch_pos()</code></a>. Note that the strings are returned in
reverse order of length; that is, the longest matching string is
given first.
</p>
<p>
Note that the DFA algorithm is slower than the standard one and it
is not able to capture substrings, so backreferences do not work.
</p>
<p>
Setting <em class="parameter"><code>start_position</code></em> differs from just passing over a shortened
string and setting <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NOTBOL:CAPS"><span class="type">G_REGEX_MATCH_NOTBOL</span></a> in the case of a pattern
that begins with any kind of lookbehind assertion, such as "\b".
</p>
<p>
A <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure, used to get information on the match, is
stored in <em class="parameter"><code>match_info</code></em> if not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. Note that if <em class="parameter"><code>match_info</code></em> is
not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> then it is created even if the function returns <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a>,
i.e. you must free it regardless if regular expression actually
matched.
</p>
<p>
<em class="parameter"><code>string</code></em> is not copied and is used in <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> internally. If
you use any <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> method (except <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-free" title="g_match_info_free ()"><code class="function">g_match_info_free()</code></a>) after
freeing or modifying <em class="parameter"><code>string</code></em> then the behaviour is undefined.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure from <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td> the string to scan for matches. <span class="annotation">[<acronym title="Parameter points to an array of items."><span class="acronym">array</span></acronym> length=string_len]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string_len</code></em> :</span></p></td>
<td>the length of <em class="parameter"><code>string</code></em>, or -1 if <em class="parameter"><code>string</code></em> is nul-terminated
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>start_position</code></em> :</span></p></td>
<td>starting index of the string to match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match options
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td> pointer to location where to store
    the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a>, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> if you do not need it. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>location to store the error occuring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> to ignore errors
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> is the string matched, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-split-simple"></a><h3>g_regex_split_simple ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> **            g_regex_split_simple                (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *pattern</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexCompileFlags" title="enum GRegexCompileFlags"><span class="type">GRegexCompileFlags</span></a> compile_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>);</pre>
<p>
Breaks the string on the pattern, and returns an array of
the tokens. If the pattern contains capturing parentheses,
then the text for each of the substrings will also be returned.
If the pattern does not match anywhere in the string, then the
whole string is returned as the first token.
</p>
<p>
This function is equivalent to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-split" title="g_regex_split ()"><code class="function">g_regex_split()</code></a> but it does
not require to compile the pattern with <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>, avoiding
some lines of code when you need just to do a split without
extracting substrings, capture counts, and so on.
</p>
<p>
If this function is to be called on the same <em class="parameter"><code>pattern</code></em> more than
once, it's more efficient to compile the pattern once with
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a> and then use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-split" title="g_regex_split ()"><code class="function">g_regex_split()</code></a>.
</p>
<p>
As a special case, the result of splitting the empty string ""
is an empty vector, not a vector containing a single string.
The reason for this special case is that being able to represent
a empty vector is typically more useful than consistent handling
of empty elements. If you do need to represent empty elements,
you'll need to check for the empty string before calling this
function.
</p>
<p>
A pattern that can match empty strings splits <em class="parameter"><code>string</code></em> into
separate characters wherever it matches the empty string between
characters. For example splitting "ab c" using as a separator
"\s*", you will get "a", "b" and "c".
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>pattern</code></em> :</span></p></td>
<td>the regular expression
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td>the string to scan for matches
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>compile_options</code></em> :</span></p></td>
<td>compile options for the regular expression, or 0
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match options, or 0
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>-terminated array of strings. Free it using <a class="link" href="glib-String-Utility-Functions.html#g-strfreev" title="g_strfreev ()"><code class="function">g_strfreev()</code></a>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-split"></a><h3>g_regex_split ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> **            g_regex_split                       (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>);</pre>
<p>
Breaks the string on the pattern, and returns an array of the tokens.
If the pattern contains capturing parentheses, then the text for each
of the substrings will also be returned. If the pattern does not match
anywhere in the string, then the whole string is returned as the first
token.
</p>
<p>
As a special case, the result of splitting the empty string "" is an
empty vector, not a vector containing a single string. The reason for
this special case is that being able to represent a empty vector is
typically more useful than consistent handling of empty elements. If
you do need to represent empty elements, you'll need to check for the
empty string before calling this function.
</p>
<p>
A pattern that can match empty strings splits <em class="parameter"><code>string</code></em> into separate
characters wherever it matches the empty string between characters.
For example splitting "ab c" using as a separator "\s*", you will get
"a", "b" and "c".
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td>the string to split with the pattern
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match time option flags
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>-terminated gchar ** array. Free it using <a class="link" href="glib-String-Utility-Functions.html#g-strfreev" title="g_strfreev ()"><code class="function">g_strfreev()</code></a>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-split-full"></a><h3>g_regex_split_full ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> **            g_regex_split_full                  (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> max_tokens</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Breaks the string on the pattern, and returns an array of the tokens.
If the pattern contains capturing parentheses, then the text for each
of the substrings will also be returned. If the pattern does not match
anywhere in the string, then the whole string is returned as the first
token.
</p>
<p>
As a special case, the result of splitting the empty string "" is an
empty vector, not a vector containing a single string. The reason for
this special case is that being able to represent a empty vector is
typically more useful than consistent handling of empty elements. If
you do need to represent empty elements, you'll need to check for the
empty string before calling this function.
</p>
<p>
A pattern that can match empty strings splits <em class="parameter"><code>string</code></em> into separate
characters wherever it matches the empty string between characters.
For example splitting "ab c" using as a separator "\s*", you will get
"a", "b" and "c".
</p>
<p>
Setting <em class="parameter"><code>start_position</code></em> differs from just passing over a shortened
string and setting <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NOTBOL:CAPS"><span class="type">G_REGEX_MATCH_NOTBOL</span></a> in the case of a pattern
that begins with any kind of lookbehind assertion, such as "\b".
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td> the string to split with the pattern. <span class="annotation">[<acronym title="Parameter points to an array of items."><span class="acronym">array</span></acronym> length=string_len]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string_len</code></em> :</span></p></td>
<td>the length of <em class="parameter"><code>string</code></em>, or -1 if <em class="parameter"><code>string</code></em> is nul-terminated
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>start_position</code></em> :</span></p></td>
<td>starting index of the string to match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>match time option flags
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>max_tokens</code></em> :</span></p></td>
<td>the maximum number of tokens to split <em class="parameter"><code>string</code></em> into.
  If this is less than 1, the string is split completely
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>return location for a <a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>-terminated gchar ** array. Free it using <a class="link" href="glib-String-Utility-Functions.html#g-strfreev" title="g_strfreev ()"><code class="function">g_strfreev()</code></a>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-replace"></a><h3>g_regex_replace ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             g_regex_replace                     (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *replacement</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Replaces all occurrences of the pattern in <em class="parameter"><code>regex</code></em> with the
replacement text. Backreferences of the form '\number' or
'\g&lt;number&gt;' in the replacement text are interpolated by the
number-th captured subexpression of the match, '\g&lt;name&gt;' refers
to the captured subexpression with the given name. '\0' refers to the
complete match, but '\0' followed by a number is the octal representation
of a character. To include a literal '\' in the replacement, write '\\'.
There are also escapes that changes the case of the following text:
</p>
<p>
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term">\l</span></p></td>
<td><p>Convert to lower case the next character</p></td>
</tr>
<tr>
<td><p><span class="term">\u</span></p></td>
<td><p>Convert to upper case the next character</p></td>
</tr>
<tr>
<td><p><span class="term">\L</span></p></td>
<td><p>Convert to lower case till \E</p></td>
</tr>
<tr>
<td><p><span class="term">\U</span></p></td>
<td><p>Convert to upper case till \E</p></td>
</tr>
<tr>
<td><p><span class="term">\E</span></p></td>
<td><p>End case modification</p></td>
</tr>
</tbody>
</table></div>
<p>
</p>
<p>
If you do not need to use backreferences use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-literal" title="g_regex_replace_literal ()"><code class="function">g_regex_replace_literal()</code></a>.
</p>
<p>
The <em class="parameter"><code>replacement</code></em> string must be UTF-8 encoded even if <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-RAW:CAPS"><span class="type">G_REGEX_RAW</span></a> was
passed to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>. If you want to use not UTF-8 encoded stings
you can use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-literal" title="g_regex_replace_literal ()"><code class="function">g_regex_replace_literal()</code></a>.
</p>
<p>
Setting <em class="parameter"><code>start_position</code></em> differs from just passing over a shortened
string and setting <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NOTBOL:CAPS"><span class="type">G_REGEX_MATCH_NOTBOL</span></a> in the case of a pattern that
begins with any kind of lookbehind assertion, such as "\b".
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td> the string to perform matches against. <span class="annotation">[<acronym title="Parameter points to an array of items."><span class="acronym">array</span></acronym> length=string_len]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string_len</code></em> :</span></p></td>
<td>the length of <em class="parameter"><code>string</code></em>, or -1 if <em class="parameter"><code>string</code></em> is nul-terminated
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>start_position</code></em> :</span></p></td>
<td>starting index of the string to match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>replacement</code></em> :</span></p></td>
<td>text to replace each match with
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>options for the match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>location to store the error occuring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> to ignore errors
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a newly allocated string containing the replacements

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-replace-literal"></a><h3>g_regex_replace_literal ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             g_regex_replace_literal             (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *replacement</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Replaces all occurrences of the pattern in <em class="parameter"><code>regex</code></em> with the
replacement text. <em class="parameter"><code>replacement</code></em> is replaced literally, to
include backreferences use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace" title="g_regex_replace ()"><code class="function">g_regex_replace()</code></a>.
</p>
<p>
Setting <em class="parameter"><code>start_position</code></em> differs from just passing over a
shortened string and setting <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NOTBOL:CAPS"><span class="type">G_REGEX_MATCH_NOTBOL</span></a> in the
case of a pattern that begins with any kind of lookbehind
assertion, such as "\b".
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td> the string to perform matches against. <span class="annotation">[<acronym title="Parameter points to an array of items."><span class="acronym">array</span></acronym> length=string_len]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string_len</code></em> :</span></p></td>
<td>the length of <em class="parameter"><code>string</code></em>, or -1 if <em class="parameter"><code>string</code></em> is nul-terminated
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>start_position</code></em> :</span></p></td>
<td>starting index of the string to match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>replacement</code></em> :</span></p></td>
<td>text to replace each match with
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>options for the match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>location to store the error occuring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> to ignore errors
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a newly allocated string containing the replacements

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-replace-eval"></a><h3>g_regex_replace_eval ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             g_regex_replace_eval                (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> *regex</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gssize" title="gssize"><span class="type">gssize</span></a> string_len</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> start_position</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexMatchFlags" title="enum GRegexMatchFlags"><span class="type">GRegexMatchFlags</span></a> match_options</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegexEvalCallback" title="GRegexEvalCallback ()"><span class="type">GRegexEvalCallback</span></a> eval</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gpointer" title="gpointer"><span class="type">gpointer</span></a> user_data</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Replaces occurrences of the pattern in regex with the output of
<em class="parameter"><code>eval</code></em> for that occurrence.
</p>
<p>
Setting <em class="parameter"><code>start_position</code></em> differs from just passing over a shortened
string and setting <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-NOTBOL:CAPS"><span class="type">G_REGEX_MATCH_NOTBOL</span></a> in the case of a pattern
that begins with any kind of lookbehind assertion, such as "\b".
</p>
<p>
The following example uses <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-eval" title="g_regex_replace_eval ()"><code class="function">g_regex_replace_eval()</code></a> to replace multiple
strings at once:
</p>
<div class="informalexample">
  <table class="listing_frame" border="0" cellpadding="0" cellspacing="0">
    <tbody>
      <tr>
        <td class="listing_lines" align="right"><pre>1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34</pre></td>
        <td class="listing_code"><pre class="programlisting"><span class="keyword">static</span><span class="normal"> <a href="glib-Basic-Types.html#gboolean">gboolean</a></span>
<span class="function">eval_cb</span><span class="normal"> </span><span class="symbol">(</span><span class="keyword">const</span><span class="normal"> </span><span class="usertype">GMatchInfo</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">info</span><span class="symbol">,</span>
<span class="normal">         </span><span class="usertype">GString</span><span class="normal">          </span><span class="symbol">*</span><span class="normal">res</span><span class="symbol">,</span>
<span class="normal">         </span><span class="usertype">gpointer</span><span class="normal">          data</span><span class="symbol">)</span>
<span class="cbracket">{</span>
<span class="normal">  </span><span class="usertype">gchar</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">match</span><span class="symbol">;</span>
<span class="normal">  </span><span class="usertype">gchar</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">r</span><span class="symbol">;</span>

<span class="normal">   match </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-match-info-fetch">g_match_info_fetch</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">info</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">);</span>
<span class="normal">   r </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Hash-Tables.html#g-hash-table-lookup">g_hash_table_lookup</a></span><span class="normal"> </span><span class="symbol">((</span><span class="normal"><a href="glib-Hash-Tables.html#GHashTable">GHashTable</a> </span><span class="symbol">*)</span><span class="normal">data</span><span class="symbol">,</span><span class="normal"> match</span><span class="symbol">);</span>
<span class="normal">   </span><span class="function"><a href="glib-Strings.html#g-string-append">g_string_append</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">res</span><span class="symbol">,</span><span class="normal"> r</span><span class="symbol">);</span>
<span class="normal">   </span><span class="function"><a href="glib-Memory-Allocation.html#g-free">g_free</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">match</span><span class="symbol">);</span>

<span class="normal">   </span><span class="keyword">return</span><span class="normal"> <a href="glib-Standard-Macros.html#FALSE:CAPS">FALSE</a></span><span class="symbol">;</span>
<span class="cbracket">}</span>

<span class="comment">/* ... */</span>

<span class="usertype">GRegex</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">reg</span><span class="symbol">;</span>
<span class="usertype">GHashTable</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">h</span><span class="symbol">;</span>
<span class="usertype">gchar</span><span class="normal"> </span><span class="symbol">*</span><span class="normal">res</span><span class="symbol">;</span>

<span class="normal">h </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Hash-Tables.html#g-hash-table-new">g_hash_table_new</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal"><a href="glib-Hash-Tables.html#g-str-hash">g_str_hash</a></span><span class="symbol">,</span><span class="normal"> <a href="glib-Hash-Tables.html#g-str-equal">g_str_equal</a></span><span class="symbol">);</span>

<span class="function"><a href="glib-Hash-Tables.html#g-hash-table-insert">g_hash_table_insert</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">h</span><span class="symbol">,</span><span class="normal"> </span><span class="string">"1"</span><span class="symbol">,</span><span class="normal"> </span><span class="string">"ONE"</span><span class="symbol">);</span>
<span class="function"><a href="glib-Hash-Tables.html#g-hash-table-insert">g_hash_table_insert</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">h</span><span class="symbol">,</span><span class="normal"> </span><span class="string">"2"</span><span class="symbol">,</span><span class="normal"> </span><span class="string">"TWO"</span><span class="symbol">);</span>
<span class="function"><a href="glib-Hash-Tables.html#g-hash-table-insert">g_hash_table_insert</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">h</span><span class="symbol">,</span><span class="normal"> </span><span class="string">"3"</span><span class="symbol">,</span><span class="normal"> </span><span class="string">"THREE"</span><span class="symbol">);</span>
<span class="function"><a href="glib-Hash-Tables.html#g-hash-table-insert">g_hash_table_insert</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">h</span><span class="symbol">,</span><span class="normal"> </span><span class="string">"4"</span><span class="symbol">,</span><span class="normal"> </span><span class="string">"FOUR"</span><span class="symbol">);</span>

<span class="normal">reg </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-regex-new">g_regex_new</a></span><span class="normal"> </span><span class="symbol">(</span><span class="string">"1|2|3|4"</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> <a href="glib-Standard-Macros.html#NULL:CAPS">NULL</a></span><span class="symbol">);</span>
<span class="normal">res </span><span class="symbol">=</span><span class="normal"> </span><span class="function"><a href="glib-Perl-compatible-regular-expressions.html#g-regex-replace-eval">g_regex_replace_eval</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">reg</span><span class="symbol">,</span><span class="normal"> text</span><span class="symbol">,</span><span class="normal"> </span><span class="symbol">-</span><span class="number">1</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> </span><span class="number">0</span><span class="symbol">,</span><span class="normal"> eval_cb</span><span class="symbol">,</span><span class="normal"> h</span><span class="symbol">,</span><span class="normal"> <a href="glib-Standard-Macros.html#NULL:CAPS">NULL</a></span><span class="symbol">);</span>
<span class="function"><a href="glib-Hash-Tables.html#g-hash-table-destroy">g_hash_table_destroy</a></span><span class="normal"> </span><span class="symbol">(</span><span class="normal">h</span><span class="symbol">);</span>

<span class="comment">/* ... */</span></pre></td>
      </tr>
    </tbody>
  </table>
</div>

<p>
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>regex</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> structure from <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string</code></em> :</span></p></td>
<td> string to perform matches against. <span class="annotation">[<acronym title="Parameter points to an array of items."><span class="acronym">array</span></acronym> length=string_len]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string_len</code></em> :</span></p></td>
<td>the length of <em class="parameter"><code>string</code></em>, or -1 if <em class="parameter"><code>string</code></em> is nul-terminated
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>start_position</code></em> :</span></p></td>
<td>starting index of the string to match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_options</code></em> :</span></p></td>
<td>options for the match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>eval</code></em> :</span></p></td>
<td>a function to call for each match
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>user_data</code></em> :</span></p></td>
<td>user data to pass to the function
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>location to store the error occuring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> to ignore errors
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a newly allocated string containing the replacements

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-regex-check-replacement"></a><h3>g_regex_check_replacement ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_regex_check_replacement           (<em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *replacement</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="type">gboolean</span></a> *has_references</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Checks whether <em class="parameter"><code>replacement</code></em> is a valid replacement string
(see <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace" title="g_regex_replace ()"><code class="function">g_regex_replace()</code></a>), i.e. that all escape sequences in
it are valid.
</p>
<p>
If <em class="parameter"><code>has_references</code></em> is not <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> then <em class="parameter"><code>replacement</code></em> is checked
for pattern references. For instance, replacement text 'foo\n'
does not contain references and may be evaluated without information
about actual match, but '\0\1' (whole match followed by first
subpattern) requires valid <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> object.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>replacement</code></em> :</span></p></td>
<td>the replacement string
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>has_references</code></em> :</span></p></td>
<td> location to store information about
  references in <em class="parameter"><code>replacement</code></em> or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>location to store error
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> whether <em class="parameter"><code>replacement</code></em> is a valid replacement string

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="GMatchInfo"></a><h3>GMatchInfo</h3>
<pre class="programlisting">typedef struct _GMatchInfo GMatchInfo;</pre>
<p>
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> is used to retrieve information about the regular expression match
which created it.
This structure is opaque and its fields cannot be accessed directly.
</p>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-get-regex"></a><h3>g_match_info_get_regex ()</h3>
<pre class="programlisting"><a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="returnvalue">GRegex</span></a> *            g_match_info_get_regex              (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);</pre>
<p>
Returns <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> object used in <em class="parameter"><code>match_info</code></em>. It belongs to Glib
and must not be freed. Use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-ref" title="g_regex_ref ()"><code class="function">g_regex_ref()</code></a> if you need to keep it
after you free <em class="parameter"><code>match_info</code></em> object.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Perl-compatible-regular-expressions.html#GRegex" title="GRegex"><span class="type">GRegex</span></a> object used in <em class="parameter"><code>match_info</code></em>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-get-string"></a><h3>g_match_info_get_string ()</h3>
<pre class="programlisting">const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *       g_match_info_get_string             (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);</pre>
<p>
Returns the string searched with <em class="parameter"><code>match_info</code></em>. This is the
string passed to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match" title="g_regex_match ()"><code class="function">g_regex_match()</code></a> or <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace" title="g_regex_replace ()"><code class="function">g_regex_replace()</code></a> so
you may not free it before calling this function.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> the string searched with <em class="parameter"><code>match_info</code></em>

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-free"></a><h3>g_match_info_free ()</h3>
<pre class="programlisting"><span class="returnvalue">void</span>                g_match_info_free                   (<em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);</pre>
<p>
Frees all the memory associated with the <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody><tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a>
</td>
</tr></tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-matches"></a><h3>g_match_info_matches ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_match_info_matches                (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);</pre>
<p>
Returns whether the previous match operation succeeded.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> if the previous match operation succeeded,
  <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-next"></a><h3>g_match_info_next ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_match_info_next                   (<em class="parameter"><code><a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Scans for the next match using the same parameters of the previous
call to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-full" title="g_regex_match_full ()"><code class="function">g_regex_match_full()</code></a> or <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match" title="g_regex_match ()"><code class="function">g_regex_match()</code></a> that returned
<em class="parameter"><code>match_info</code></em>.
</p>
<p>
The match is done on the string passed to the match function, so you
cannot free it before calling this function.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>location to store the error occuring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> to ignore errors
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> is the string matched, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-get-match-count"></a><h3>g_match_info_get_match_count ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="returnvalue">gint</span></a>                g_match_info_get_match_count        (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);</pre>
<p>
Retrieves the number of matched substrings (including substring 0,
that is the whole matched text), so 1 is returned if the pattern
has no substrings in it and 0 is returned if the match failed.
</p>
<p>
If the last match was obtained using the DFA algorithm, that is
using <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all" title="g_regex_match_all ()"><code class="function">g_regex_match_all()</code></a> or <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all-full" title="g_regex_match_all_full ()"><code class="function">g_regex_match_all_full()</code></a>, the retrieved
count is not that of the number of capturing parentheses but that of
the number of matched substrings.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> Number of matched substrings, or -1 if an error occurred

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-is-partial-match"></a><h3>g_match_info_is_partial_match ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_match_info_is_partial_match       (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);</pre>
<p>
Usually if the string passed to g_regex_match*() matches as far as
it goes, but is too short to match the entire pattern, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> is
returned. There are circumstances where it might be helpful to
distinguish this case from other cases in which there is no match.
</p>
<p>
Consider, for example, an application where a human is required to
type in data for a field with specific formatting requirements. An
example might be a date in the form ddmmmyy, defined by the pattern
"^\d?\d(jan|feb|mar|apr|may|jun|jul|aug|sep|oct|nov|dec)\d\d$".
If the application sees the user’s keystrokes one by one, and can
check that what has been typed so far is potentially valid, it is
able to raise an error as soon as a mistake is made.
</p>
<p>
GRegex supports the concept of partial matching by means of the
<a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-PARTIAL:CAPS"><span class="type">G_REGEX_MATCH_PARTIAL</span></a> flag. When this is set the return code for
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match" title="g_regex_match ()"><code class="function">g_regex_match()</code></a> or <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-full" title="g_regex_match_full ()"><code class="function">g_regex_match_full()</code></a> is, as usual, <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a>
for a complete match, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise. But, when these functions
return <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a>, you can check if the match was partial calling
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-match-info-is-partial-match" title="g_match_info_is_partial_match ()"><code class="function">g_match_info_is_partial_match()</code></a>.
</p>
<p>
When using partial matching you cannot use g_match_info_fetch*().
</p>
<p>
Because of the way certain internal optimizations are implemented
the partial matching algorithm cannot be used with all patterns.
So repeated single characters such as "a{2,4}" and repeated single
meta-sequences such as "\d+" are not permitted if the maximum number
of occurrences is greater than one. Optional items such as "\d?"
(where the maximum is one) are permitted. Quantifiers with any values
are permitted after parentheses, so the invalid examples above can be
coded thus "(a){2,4}" and "(\d)+". If <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-MATCH-PARTIAL:CAPS"><span class="type">G_REGEX_MATCH_PARTIAL</span></a> is set
for a pattern that does not conform to the restrictions, matching
functions return an error.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> if the match was partial, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-expand-references"></a><h3>g_match_info_expand_references ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             g_match_info_expand_references      (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *string_to_expand</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Error-Reporting.html#GError" title="GError"><span class="type">GError</span></a> **error</code></em>);</pre>
<p>
Returns a new string containing the text in <em class="parameter"><code>string_to_expand</code></em> with
references and escape sequences expanded. References refer to the last
match done with <em class="parameter"><code>string</code></em> against <em class="parameter"><code>regex</code></em> and have the same syntax used by
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-replace" title="g_regex_replace ()"><code class="function">g_regex_replace()</code></a>.
</p>
<p>
The <em class="parameter"><code>string_to_expand</code></em> must be UTF-8 encoded even if <a class="link" href="glib-Perl-compatible-regular-expressions.html#G-REGEX-RAW:CAPS"><span class="type">G_REGEX_RAW</span></a> was
passed to <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-new" title="g_regex_new ()"><code class="function">g_regex_new()</code></a>.
</p>
<p>
The backreferences are extracted from the string passed to the match
function, so you cannot call this function after freeing the string.
</p>
<p>
<em class="parameter"><code>match_info</code></em> may be <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> in which case <em class="parameter"><code>string_to_expand</code></em> must not
contain references. For instance "foo\n" does not refer to an actual
pattern and '\n' merely will be replaced with \n character,
while to expand "\0" (whole match) one needs the result of a match.
Use <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-check-replacement" title="g_regex_check_replacement ()"><code class="function">g_regex_check_replacement()</code></a> to find out whether <em class="parameter"><code>string_to_expand</code></em>
contains references.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>string_to_expand</code></em> :</span></p></td>
<td>the string to expand
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>error</code></em> :</span></p></td>
<td>location to store the error occuring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> to ignore errors
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> the expanded string, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> if an error occurred. <span class="annotation">[<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-fetch"></a><h3>g_match_info_fetch ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             g_match_info_fetch                  (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> match_num</code></em>);</pre>
<p>
Retrieves the text matching the <em class="parameter"><code>match_num</code></em>'th capturing
parentheses. 0 is the full text of the match, 1 is the first paren
set, 2 the second, and so on.
</p>
<p>
If <em class="parameter"><code>match_num</code></em> is a valid sub pattern but it didn't match anything
(e.g. sub pattern 1, matching "b" against "(a)?b") then an empty
string is returned.
</p>
<p>
If the match was obtained using the DFA algorithm, that is using
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all" title="g_regex_match_all ()"><code class="function">g_regex_match_all()</code></a> or <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all-full" title="g_regex_match_all_full ()"><code class="function">g_regex_match_all_full()</code></a>, the retrieved
string is not that of a set of parentheses but that of a matched
substring. Substrings are matched in reverse order of length, so
0 is the longest match.
</p>
<p>
The string is fetched from the string passed to the match function,
so you cannot call this function after freeing the string.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_num</code></em> :</span></p></td>
<td>number of the sub expression
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> The matched substring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> if an error
    occurred. You have to free the string yourself. <span class="annotation">[<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-fetch-pos"></a><h3>g_match_info_fetch_pos ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_match_info_fetch_pos              (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> match_num</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> *start_pos</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> *end_pos</code></em>);</pre>
<p>
Retrieves the position in bytes of the <em class="parameter"><code>match_num</code></em>'th capturing
parentheses. 0 is the full text of the match, 1 is the first
paren set, 2 the second, and so on.
</p>
<p>
If <em class="parameter"><code>match_num</code></em> is a valid sub pattern but it didn't match anything
(e.g. sub pattern 1, matching "b" against "(a)?b") then <em class="parameter"><code>start_pos</code></em>
and <em class="parameter"><code>end_pos</code></em> are set to -1 and <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> is returned.
</p>
<p>
If the match was obtained using the DFA algorithm, that is using
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all" title="g_regex_match_all ()"><code class="function">g_regex_match_all()</code></a> or <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all-full" title="g_regex_match_all_full ()"><code class="function">g_regex_match_all_full()</code></a>, the retrieved
position is not that of a set of parentheses but that of a matched
substring. Substrings are matched in reverse order of length, so
0 is the longest match.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_num</code></em> :</span></p></td>
<td>number of the sub expression
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>start_pos</code></em> :</span></p></td>
<td> pointer to location where to store
    the start position, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>end_pos</code></em> :</span></p></td>
<td> pointer to location where to store
    the end position, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> if the position was fetched, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise. If
  the position cannot be fetched, <em class="parameter"><code>start_pos</code></em> and <em class="parameter"><code>end_pos</code></em> are left
  unchanged

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-fetch-named"></a><h3>g_match_info_fetch_named ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> *             g_match_info_fetch_named            (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *name</code></em>);</pre>
<p>
Retrieves the text matching the capturing parentheses named <em class="parameter"><code>name</code></em>.
</p>
<p>
If <em class="parameter"><code>name</code></em> is a valid sub pattern name but it didn't match anything
(e.g. sub pattern "X", matching "b" against "(?P&lt;X&gt;a)?b")
then an empty string is returned.
</p>
<p>
The string is fetched from the string passed to the match function,
so you cannot call this function after freeing the string.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>name</code></em> :</span></p></td>
<td>name of the subexpression
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> The matched substring, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> if an error
    occurred. You have to free the string yourself. <span class="annotation">[<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-fetch-named-pos"></a><h3>g_match_info_fetch_named_pos ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gboolean" title="gboolean"><span class="returnvalue">gboolean</span></a>            g_match_info_fetch_named_pos        (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>,
                                                         <em class="parameter"><code>const <a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="type">gchar</span></a> *name</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> *start_pos</code></em>,
                                                         <em class="parameter"><code><a class="link" href="glib-Basic-Types.html#gint" title="gint"><span class="type">gint</span></a> *end_pos</code></em>);</pre>
<p>
Retrieves the position in bytes of the capturing parentheses named <em class="parameter"><code>name</code></em>.
</p>
<p>
If <em class="parameter"><code>name</code></em> is a valid sub pattern name but it didn't match anything
(e.g. sub pattern "X", matching "b" against "(?P&lt;X&gt;a)?b")
then <em class="parameter"><code>start_pos</code></em> and <em class="parameter"><code>end_pos</code></em> are set to -1 and <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> is returned.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>
<a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>name</code></em> :</span></p></td>
<td>name of the subexpression
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>start_pos</code></em> :</span></p></td>
<td> pointer to location where to store
    the start position, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><em class="parameter"><code>end_pos</code></em> :</span></p></td>
<td> pointer to location where to store
    the end position, or <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>. <span class="annotation">[<acronym title="Parameter for returning results. Default is transfer full."><span class="acronym">out</span></acronym>][<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> <a class="link" href="glib-Standard-Macros.html#TRUE:CAPS" title="TRUE"><code class="literal">TRUE</code></a> if the position was fetched, <a class="link" href="glib-Standard-Macros.html#FALSE:CAPS" title="FALSE"><code class="literal">FALSE</code></a> otherwise.
    If the position cannot be fetched, <em class="parameter"><code>start_pos</code></em> and <em class="parameter"><code>end_pos</code></em>
    are left unchanged.

</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
<hr>
<div class="refsect2">
<a name="g-match-info-fetch-all"></a><h3>g_match_info_fetch_all ()</h3>
<pre class="programlisting"><a class="link" href="glib-Basic-Types.html#gchar" title="gchar"><span class="returnvalue">gchar</span></a> **            g_match_info_fetch_all              (<em class="parameter"><code>const <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> *match_info</code></em>);</pre>
<p>
Bundles up pointers to each of the matching substrings from a match
and stores them in an array of gchar pointers. The first element in
the returned array is the match number 0, i.e. the entire matched
text.
</p>
<p>
If a sub pattern didn't match anything (e.g. sub pattern 1, matching
"b" against "(a)?b") then an empty string is inserted.
</p>
<p>
If the last match was obtained using the DFA algorithm, that is using
<a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all" title="g_regex_match_all ()"><code class="function">g_regex_match_all()</code></a> or <a class="link" href="glib-Perl-compatible-regular-expressions.html#g-regex-match-all-full" title="g_regex_match_all_full ()"><code class="function">g_regex_match_all_full()</code></a>, the retrieved
strings are not that matched by sets of parentheses but that of the
matched substring. Substrings are matched in reverse order of length,
so the first one is the longest match.
</p>
<p>
The strings are fetched from the string passed to the match function,
so you cannot call this function after freeing the string.
</p>
<div class="variablelist"><table border="0">
<col align="left" valign="top">
<tbody>
<tr>
<td><p><span class="term"><em class="parameter"><code>match_info</code></em> :</span></p></td>
<td>a <a class="link" href="glib-Perl-compatible-regular-expressions.html#GMatchInfo" title="GMatchInfo"><span class="type">GMatchInfo</span></a> structure
</td>
</tr>
<tr>
<td><p><span class="term"><span class="emphasis"><em>Returns</em></span> :</span></p></td>
<td> a <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a>-terminated array of gchar * pointers.
    It must be freed using <a class="link" href="glib-String-Utility-Functions.html#g-strfreev" title="g_strfreev ()"><code class="function">g_strfreev()</code></a>. If the previous match failed
    <a class="link" href="glib-Standard-Macros.html#NULL:CAPS" title="NULL"><code class="literal">NULL</code></a> is returned. <span class="annotation">[<acronym title="NULL is ok, both for passing and for returning."><span class="acronym">allow-none</span></acronym>]</span>
</td>
</tr>
</tbody>
</table></div>
<p class="since">Since 2.14</p>
</div>
</div>
<div class="refsect1">
<a name="glib-Perl-compatible-regular-expressions.see-also"></a><h2>See Also</h2>
<a class="xref" href="glib-regex-syntax.html" title="Regular expression syntax"><span class="refentrytitle">Regular expression syntax</span></a>
</div>
</div>
<div class="footer">
<hr>
          Generated by GTK-Doc V1.15.1</div>
</body>
</html>