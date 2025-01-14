<!-- 	Silicon Graphics, Inc.
	CRAYDOCBK DTD text stylesheet
	Software Publications
	InSight/DynaText version
	December 21, 1998
	last updated by: Adrian Daley (agd@sgi.com)
	IRIS InSight Viewer Stylesheet (Version 3.9a)
-->

<!-- Common Entities -->
<!ENTITY	admonitions.left-indent	CDATA	"+=30"	>
<!ENTITY	big-float.space-after	CDATA	"if(eq(rsibling(),0),0,17)"	>
<!ENTITY	body.foreground		CDATA	"if(env(INSIGHT_FG),env(INSIGHT_FG),grey20)"	>
<!ENTITY	body.left-indent	CDATA	"48"	>
<!ENTITY	body.right-indent	CDATA	"10"	>
<!ENTITY	captions.font-weight	CDATA	"Medium"	>
<!ENTITY	captions.foreground	CDATA	"if(env(INSIGHT_FG),env(INSIGHT_FG),Black)"	>
<!ENTITY	float-value		CDATA	"8"	>
<!ENTITY	float.space-after	CDATA	"if(eq(rsibling(),0),0,8)"	>
<!ENTITY	float.space-before	CDATA	"if(ancestor(me(),para,1),8,0)"	>
<!ENTITY	hanging-indent		CDATA	"-15"	>
<!ENTITY	hot-text.foreground	CDATA	"#000078"	>
<!ENTITY	listitems.left-indent	CDATA	"+=15"	>
<!ENTITY	lists.left-indent	CDATA	"+=0"	>
<!ENTITY	row.space-before	CDATA	"8"	>
<!ENTITY	smaller.font-size	CDATA	"-=2"	>
<!ENTITY	sub.vertical-offset	CDATA	"-3"	>
<!ENTITY	super.vertical-offset	CDATA	"4"	>
<!ENTITY	titles-italic.font-slant	CDATA	"Italics"	>
<!ENTITY	titles.font-family	CDATA	"helvetica"	>
<!ENTITY	titles.font-weight	CDATA	"Bold"	>
<!ENTITY	titles.foreground	CDATA	"if(env(INSIGHT_FG),env(INSIGHT_FG),Black)"	>
<!ENTITY	titles.left-indent	CDATA	"0"	>
<!ENTITY	titles.space-after	CDATA	"8"	>

<!-- IRIS InSight and SGI Help Specific Entities -->
<!ENTITY	body.font-family	CDATA	"New Century Schoolbook"	>
<!ENTITY	body.font-size		CDATA	"12"	>
<!ENTITY	body.line-spacing	CDATA	"17"	>
<!ENTITY	captions.font-family	CDATA	"New Century Schoolbook"	>
<!ENTITY	captions.font-size	CDATA	"12"	>
<!ENTITY	captions.line-spacing	CDATA	"28"	>
<!ENTITY	command.font-family	CDATA	"Courier"	>
<!ENTITY	command.font-size	CDATA	"12"	>
<!ENTITY	table.font-size		CDATA	"12"	>
<!ENTITY	titles-a.font-size	CDATA	"24"	>
<!ENTITY	titles-a.line-spacing	CDATA	"28"	>
<!ENTITY	titles-b.font-size	CDATA	"22"	>
<!ENTITY	titles-b.line-spacing	CDATA	"26"	>
<!ENTITY	titles-c.font-size	CDATA	"18"	>
<!ENTITY	titles-c.line-spacing	CDATA	"22"	>
<!ENTITY	titles-d.font-size	CDATA	"14"	>
<!ENTITY	titles-d.line-spacing	CDATA	"17"	>
<!ENTITY	titles-e.font-size	CDATA	"12"	>
<!ENTITY	titles-e.line-spacing	CDATA	"17"	>


<sheet >

<?INSTED COMMENT: GROUP ADMONITIONS>

<!-- Admonitions and blockquote. -->
<group name="ADMONITIONS">
	<break-before>	Line				</>
	<break-after>	Line				</>
	<font-family>	&body.font-family		</>
	<font-weight>	&body.font-weight		</>
	<font-size>	&body.font-size			</>
	<left-indent>	+=15				</>
	<right-indent>	+=15				</>
	<space-before>	&float.space-before		</>
	<space-after>	&float.space-after		</>
</group>

<style name="CAUTION" group="ADMONITIONS">
	<icon-position>	Left	</>
	<icon-type>	caution	</>
	<text-before>Caution: </>
</style>

<style name="IMPORTANT" group="ADMONITIONS">
	<text-before>Important: </>
</style>

<style name="NOTE" group="ADMONITIONS">
	<select>if(attr(role),NOTE.attr(role),NOTE.DEFAULT)</>
</style>

<style name="NOTE.DEFAULT" group="ADMONITIONS">
	<text-before>Note: </>
</style>

<style name="NOTE.ANSI-ISO" group="ADMONITIONS">
	<text-before>ANSI/ISO: </>
</style>

<style name="NOTE.OPENMP" group="ADMONITIONS">
	<text-before>OpenMP: </>
</style>

<style name="TIP" group="ADMONITIONS">
	<text-before>Tip: </>
</style>

<style name="WARNING" group="ADMONITIONS">
	<icon-position>	Left	</>
	<icon-type>	warn	</>
	<text-before>Warning: </>
</style>



<?INSTED COMMENT: GROUP ADMONITIONS.TEXT-BEFORE>

<group name="ADMONITIONS.TEXT-BEFORE">
	<font-family>	&titles.font-family	</>
	<font-weight>	&titles.font-weight	</>
	<font-size>	&titles-c.font-size	</>
	<foreground>	&titles.foreground	</>
</group>



<style name="CAUTION,#TEXT-BEFORE" group="ADMONITIONS.TEXT-BEFORE">
</style>

<style name="CAUTION,TITLE" group="ADMONITIONS.TEXT-BEFORE">
	<hide>	All	</>
</style>

<style name="IMPORTANT,#TEXT-BEFORE" group="ADMONITIONS.TEXT-BEFORE">
</style>

<style name="IMPORTANT,TITLE" group="ADMONITIONS.TEXT-BEFORE">
	<hide>	All	</>
</style>

<style name="NOTE,#TEXT-BEFORE" group="ADMONITIONS.TEXT-BEFORE">
</style>

<style name="NOTE,TITLE" group="ADMONITIONS.TEXT-BEFORE">
	<hide>	All	</>
</style>

<style name="TIP,#TEXT-BEFORE" group="ADMONITIONS.TEXT-BEFORE">
</style>

<style name="TIP,TITLE" group="ADMONITIONS.TEXT-BEFORE">
	<hide>	All	</>
</style>

<style name="WARNING,#TEXT-BEFORE" group="ADMONITIONS.TEXT-BEFORE">
</style>

<style name="WARNING,TITLE" group="ADMONITIONS.TEXT-BEFORE">
	<hide>	All	</>
</style>



<?INSTED COMMENT: GROUP FIXED.WIDTH.LAYOUT>

<!-- Structured character formats. -->
<group name="FIXED.WIDTH.LAYOUT">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
	<line-spacing>	8			</>
	<space-before>	if(ancestor(ENTRY),,if(ancestor(me(),para,1),8,0))	</>
	<space-after>	&float.space-after	</>
	<justification>	Verbatim		</>
</group>

<style name="INTERFACEDEFINITION" group="FIXED.WIDTH.LAYOUT">
	<line-spacing>	&captions.line-spacing	</>
	<justification>	Left	</>
	<break-before>	Line	</>
</style>

<style name="LITERALLAYOUT" group="FIXED.WIDTH.LAYOUT">
	<left-indent>	if(ancestor(LISTITEM),+=15,)	</>
	<justification>	Verbatim	</>
</style>

<style name="PROGRAMLISTING" group="FIXED.WIDTH.LAYOUT">
	<left-indent>	if(ancestor(LISTITEM),+=15,)	</>
</style>

<style name="SCREEN" group="FIXED.WIDTH.LAYOUT">
</style>


<?INSTED COMMENT: GROUP H1>

<!-- Titles. -->
<group name="H1">
	<font-family>	&titles.font-family	</>
	<font-weight>	&titles.font-weight	</>
	<font-size>	&titles-a.font-size	</>
	<foreground>	&titles.foreground	</>
	<left-indent>	&titles.left-indent	</>
	<line-spacing>	&titles-a.line-spacing	</>
	<space-before>	36			</>
	<space-after>	&titles.space-after	</>
</group>

<style name="APPENDIX,TITLE" group="H1">
	<hrule>	Before	</>
	<text-before>Appendix format(gcnum(ancestor(appendix)),LETTER). </>
</style>

<style name="BOOK,TITLE" group="H1">
</style>

<style name="CHAPTER,TITLE" group="H1">
	<hrule>	Before	</>
	<text-before>Chapter gcnum(ancestor(chapter)). </>
</style>

<style name="GLOSSARY,TITLE" group="H1">
	<hrule>	Before	</>
</style>

<style name="PART,TITLE" group="H1">
	<hrule>	Before	</>
	<text-before>Part gcnum(ancestor(part)). </>
</style>

<style name="PREFACE,TITLE" group="H1">
	<hrule>	Before	</>
</style>



<?INSTED COMMENT: GROUP H1.TEXT-BEFORE>

<group name="H1.TEXT-BEFORE">
	<font-family>	&titles.font-family	</>
	<font-weight>	&titles.font-weight	</>
	<font-slant>	&titles-italic.font-slant	</>
	<font-size>	&titles-c.font-size	</>
	<foreground>	&titles.foreground	</>
	<line-spacing>	&titles-c.line-spacing	</>
	<break-after>	True	</>
</group>

<style name="APPENDIX,TITLE,#TEXT-BEFORE" group="H1.TEXT-BEFORE">
</style>

<style name="CHAPTER,TITLE,#TEXT-BEFORE" group="H1.TEXT-BEFORE">
</style>

<style name="PART,TITLE,#TEXT-BEFORE" group="H1.TEXT-BEFORE">
</style>

<style name="PUBNUMBER" group="H1.TEXT-BEFORE">
	<space-before>	12	</>
	<space-after>	&float.space-after	</>
</style>

<style name="PARTNUMBER" group="H1.TEXT-BEFORE">
	<hide>	Children	</>
</style>

<style name="PUBNUMBER,#TEXT-BEFORE" group="H1.TEXT-BEFORE">
	<break-after>	False	</>
</style>

<style name="PARTNUMBER,#TEXT-BEFORE" group="H1.TEXT-BEFORE">
	<break-after>	False	</>
</style>


<?INSTED COMMENT: GROUP H2>

<group name="H2">
	<font-family>	&titles.font-family	</>
	<font-weight>	&titles.font-weight	</>
	<font-size>	&titles-b.font-size	</>
	<foreground>	&titles.foreground	</>
	<left-indent>	&titles.left-indent	</>
	<line-spacing>	&titles-b.line-spacing	</>
	<space-after>	&titles.space-after	</>
	<break-before>	True	</>
</group>

<style name="ACKNOWLEDGEMENTS,#TEXT-BEFORE" group="H2">
</style>

<style name="APPENDIX,SECTION,TITLE" group="H2">
	<text-before>format(gcnum(ancestor(appendix)),LETTER).cnum(ancestor(section)) </>
</style>

<style name="CHAPTER,SECTION,TITLE" group="H2">
	<text-before>gcnum(ancestor(chapter)).cnum(ancestor(section)) </>
</style>

<style name="NEWFEATURES,TITLE" group="H2">
	<left-indent>	48	</>
</style>

<style name="PREFACE,SECTION,TITLE" group="H2">
</style>

<style name="REVHISTORY,#TEXT-BEFORE" group="H2">
	<break-after>	Line	</>
</style>



<?INSTED COMMENT: GROUP H3>

<group name="H3">
	<font-family>	&titles.font-family	</>
	<font-weight>	&titles.font-weight	</>
	<font-slant>	&titles-italic.font-slant	</>
	<font-size>	&titles-c.font-size	</>
	<foreground>	&titles.foreground	</>
	<left-indent>	&titles.left-indent	</>
	<line-spacing>	&titles-c.line-spacing	</>
	<space-after>	&titles.space-after	</>
	<break-before>	True	</>
</group>

<style name="APPENDIX,SECTION,SECTION,TITLE" group="H3">
	<text-before>format(gcnum(ancestor(appendix)),LETTER).cnum(ancestor(me(),section,2)).cnum(ancestor(section)) </>
</style>

<style name="CHAPTER,SECTION,SECTION,TITLE" group="H3">
	<text-before>gcnum(ancestor(chapter)).cnum(ancestor(me(),section,2)).cnum(ancestor(section)) </>
</style>

<style name="PROCEDURE,#TEXT-BEFORE" group="H3">
	<left-indent>	+=0	</>
</style>

<style name="PROCEDURE,TITLE" group="H3">
	<left-indent>	+=0	</>
	<text-before>Procedure gcnum(ancestor(procedure)): </>
</style>

<?INSTED COMMENT: GROUP H4>

<group name="H4">
	<font-family>	&titles.font-family	</>
	<font-weight>	&titles.font-weight	</>
	<font-slant>	&titles-italic.font-slant	</>
	<font-size>	&titles-d.font-size	</>
	<foreground>	&titles.foreground	</>
	<left-indent>	&titles.left-indent	</>
	<line-spacing>	&titles-d.line-spacing	</>
	<space-after>	&titles.space-after	</>
	<break-before>	True	</>
</group>

<style name="APPENDIX,SECTION,SECTION,SECTION,TITLE" group="H4">
	<text-before>format(gcnum(ancestor(appendix)),LETTER).cnum(ancestor(me(),section,3)).cnum(ancestor(me(),section,2)).cnum(ancestor(section)) </>
</style>

<style name="CHAPTER,SECTION,SECTION,SECTION,TITLE" group="H4">
	<text-before>gcnum(ancestor(chapter)).cnum(ancestor(me(),section, 3)).cnum(ancestor(me(),section,2)).cnum(ancestor(section)) </>
</style>



<?INSTED COMMENT: GROUP H5>

<group name="H5">
	<font-family>	&titles.font-family	</>
	<font-weight>	&titles.font-weight	</>
	<font-slant>	&titles-italic.font-slant	</>
	<font-size>	&titles-e.font-size	</>
	<foreground>	&titles.foreground	</>
	<left-indent>	&titles.left-indent	</>
	<line-spacing>	&titles-e.line-spacing	</>
	<space-after>	&float.space-after	</>
	<break-before>	True	</>
</group>

<style name="REVISION,#TEXT-BEFORE" group="H5">
	<break-after>	Line	</>
</style>

<style name="APPENDIX,SECTION,SECTION,SECTION,SECTION,TITLE" group="H5">
	<font-slant>	Italics	</>
	<text-before>format(gcnum(ancestor(appendix)),LETTER).cnum(ancestor(me(),section,4)).cnum(ancestor(me(),section,3)).cnum(ancestor(me(),section,2)).cnum(ancestor(section)) </>
</style>

<style name="CHAPTER,SECTION,SECTION,SECTION,SECTION,TITLE" group="H5">
	<font-slant>	Italics	</>
	<text-before>gcnum(ancestor(chapter)).cnum(ancestor(me(),section,4)).cnum(ancestor(me(),section,3)).cnum(ancestor(me(),section,2)).cnum(ancestor(section)) </>
</style>


<?INSTED COMMENT: GROUP H6>

<group name="H6">
	<!-- H6 titles are for non-caption headings -->
	<font-family>	&body.font-family	</>
	<font-size>	&titles-d.font-size	</>
	<line-spacing>	&titles-d.line-spacing	</>
	<space-after>	&float.space-after	</>
	<justification>	Left	</>
	<break-before>	True	</>
</group>

<style name="ABSTRACT,TITLE" group="H6">
</style>

<style name="DEFLIST,TITLE" group="H6">
</style>

<style name="EQUATION,TITLE" group="H6">
</style>

<style name="SCREENSHOT,TITLE" group="H6">
</style>


<?INSTED COMMENT: GROUP CAPTIONS>

<group name="CAPTIONS">
	<!-- CAPTIONS are for tables, etc. -->
	<font-family>	&captions.font-family	</>
	<font-weight>	&captions.font-weight	</>
	<font-size>	&captions.font-size	</>
	<foreground>	&captions.foreground	</>
	<line-spacing>	&captions.line-spacing	</>
	<space-after>	&float.space-after	</>
	<justification>	Left	</>
	<break-before>	True	</>
</group>

<style name="EXAMPLE,TITLE" group="CAPTIONS">
	<text-before>Example gcnum(ancestor(example)). </>
</style>

<style name="FIGURE,TITLE" group="CAPTIONS">
	<text-before>Figure gcnum(ancestor(figure)). </>
</style>

<style name="TABLE,TITLE" group="CAPTIONS">
	<text-before>Table gcnum(ancestor(table)). </>
</style>

<style name="TABLE,#TEXT-BEFORE" group="CAPTIONS">
</style>

<?INSTED COMMENT: GROUP LISTITEMS>

<group name="LISTITEMS">
	<space-after>	&float.space-after	</>
</group>

<style name="ITEMIZEDLIST,LISTITEM" group="LISTITEMS">
	<text-before>if(ancestor(me(),itemizedlist,3),*,if(ancestor(me(),itemizedlist,2),-,�))</>
</style>

<style name="MEMBER" group="LISTITEMS">
	<left-indent>	+=0	</>
	<first-indent>	0	</>
	<line-spacing>	13	</>
	<space-after>	1	</>
	<select>	if(eq(attr(type,ancestor(simplelist)),inline),     MEMBER.INLINE,     MEMBER)	</>
</style>

<style name="ORDEREDLIST,LISTITEM" group="LISTITEMS">
	<text-before>format(cnum(),   if(ancestor(me(),orderedlist,3),    roman,    if(ancestor(me(),orderedlist,2),     letter2,     decimal))). </>
</style>

<style name="STEP" group="LISTITEMS">
	<text-before>format(cnum(),   if(ancestor(me(),substeps,2),    roman,    if(ancestor(me(),substeps,1),     letter2,     decimal))). </>
	<left-indent>	+=15			</>
	<space-after>	&float.space-after	</>
	<break-before>	if(lsibling(TITLE),false,true)</>
</style>

<?INSTED COMMENT: GROUP LISTS>

<!-- List elements. -->
<group name="LISTS">
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
</group>

<style name="ITEMIZEDLIST" group="LISTS">
</style>

<style name="ORDEREDLIST" group="LISTS">
</style>

<style name="PROCEDURE" group="LISTS">
	<text-before>if(not(typechild(title)),Procedure gcnum(),)</>
</style>

<style name="SIMPLELIST" group="LISTS">
	<select>	if(eq(attr(type),inline),SIMPLELIST.INLINE,SIMPLELIST)	</>
</style>

<style name="SUBSTEPS" group="LISTS">
	<left-indent>	+=15	</>
</style>



<?INSTED COMMENT: GROUP TOC>

<!-- Significant elements for the TOC. -->
<group name="TOC">
	<space-after>	&big-float.space-after	</>
	<break-before>	Line	</>
</group>

<style name="APPENDIX" group="TOC">
</style>

<style name="BOOK" group="TOC">
</style>

<style name="CHAPTER" group="TOC">
</style>

<style name="DOCBOOK" group="TOC">
	<font-family>	&body.font-family	</>
	<font-size>	&body.font-size	</>
	<foreground>	&body.foreground	</>
	<left-indent>	&body.left-indent	</>
	<right-indent>	&body.right-indent	</>
	<line-spacing>	&body.line-spacing	</>
</style>

<style name="GLOSSARY" group="TOC">
</style>

<style name="INDEX" group="TOC">
</style>

<style name="PART" group="TOC">
</style>

<style name="PREFACE" group="TOC">
</style>

<style name="SECTION" group="TOC">
</style>



<?INSTED COMMENT: GROUP xrefs>

<group name="xrefs">
	<foreground>	&hot-text.foreground	</>
	<score>	Under	</>
	<script>	ebt-link root=idmatch(ID,attr(LINKEND))	</>
</group>

<!-- XREF. This style selects an XREF.element style:

if(xref has xreflabel attribute) 
  then select xreflabel style;
else if(linkend of xref is a title) 
  then select style for linkend's ancestor;
else select style for linkend;

Each style, XREF.element, generates customized hot-text.

Programming note: The select statement breaks unless the DEFAULT item 
of gamut() is protected by join().
-->
<style name="XREF" group="xrefs">
	<select>	XREF.if(attr(xreflabel, me()),XREFLABEL,gamut(if(eq(tag(idmatch(attr(linkend))),title), tag(ancestor(idmatch(attr(linkend)))), tag(idmatch(attr(linkend)))), 'appendix chapter equation example figure inlineequation para preface procedure section step table','APPENDIX CHAPTER EQUATION EXAMPLE FIGURE INLINEEQUATION PARA PREFACE PROCEDURE SECTION STEP TABLE', join('DEFAULT')))	</>
</style>

<style name="XREF.APPENDIX" group="xrefs">
	<text-before>Appendix format(gcnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend)))), LETTER)</>
</style>

<style name="XREF.CHAPTER" group="xrefs">
	<text-before>Chapter gcnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend))))</>
</style>

<style name="XREF.DEFAULT" group="xrefs">
	<text-before>[Click here]</>
</style>

<style name="XREF.EQUATION" group="xrefs">
	<text-before>Equation gcnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend))))</>
</style>

<style name="XREF.EXAMPLE" group="xrefs">
	<text-before>Example gcnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend))))</>
</style>

<style name="XREF.FIGURE" group="xrefs">
	<text-before>Figure gcnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend))))</>
</style>

<style name="XREF.INLINEEQUATION" group="xrefs">
	<text-before>Inline Equation gcnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend))))</>
</style>

<style name="XREF.PARA" group="xrefs">
	<text-before>[Click here]</>
</style>

<style name="XREF.PREFACE" group="xrefs">
	<text-before>Preface</>
</style>

<style name="XREF.PROCEDURE" group="xrefs">
	<text-before>Procedure gcnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend))))</>
</style>

<!-- XREF.SECTION. Here's a little monster. The enumeration depends on 
ancestor sections and chapter/appendix/preface. The xref may point to 
either the section or its title.
-->
<style name="XREF.SECTION" group="xrefs">
	<text-before>if(ancestor(idmatch(attr(linkend)),preface),Preface Section ,Section )if(ancestor(idmatch(attr(linkend)),chapter),gcnum(ancestor(idmatch(attr(linkend)),chapter)).,)if(ancestor(idmatch(attr(linkend)),appendix),format(gcnum(ancestor(idmatch(attr(linkend)),appendix)),LETTER).,)if(ancestor(idmatch(attr(linkend)),section,4),cnum(ancestor(idmatch(attr(linkend)),section,4)).,)if(ancestor(idmatch(attr(linkend)),section,3),cnum(ancestor(idmatch(attr(linkend)),section,3)).,)if(ancestor(idmatch(attr(linkend)),section,2),cnum(ancestor(idmatch(attr(linkend)),section,2)).,)if(ancestor(idmatch(attr(linkend)),section,1),cnum(ancestor(idmatch(attr(linkend)),section,1)),)if(eq(tag(idmatch(attr(linkend))),title),,if(ancestor(idmatch(attr(linkend)),section,1),.,)cnum(idmatch(attr(linkend))))</>
</style>

<style name="XREF.STEP" group="xrefs">
	<text-before>Procedure gcnum(ancestor(idmatch(attr(linkend)),procedure)), Step cnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend))))</>
</style>

<style name="XREF.TABLE" group="xrefs">
	<text-before>Table gcnum(if(eq(tag(idmatch(attr(linkend))),title), ancestor(idmatch(attr(linkend))), idmatch(attr(linkend))))</>
</style>

<style name="XREF.XREFLABEL" group="xrefs">
	<text-before>attr(xreflabel,me())</>
</style>



<?INSTED COMMENT: UNGROUPED STYLES FOLLOW>

<style name="#ROOT">
	<break-before>	Line	</>
</style>

<!-- Default settings for SDATA entities from our entity sets -->
<style name="#SDATA">
	<font-family>	attr(font)	</>
	<font-weight>	Medium	</>
	<font-slant>	Roman	</>
	<character-set>	attr(charset)	</>
	<break-before>	None	</>
	<text-before>char(attr(code))</>
</style>

<style name="#TAGS">
	<font-weight>	Bold	</>
</style>

<!-- Miscellaneous styles. -->
<style name="ABSTRACT">
	<select>	BLOCKQUOTE	</>
</style>

<style name="ACCEL">
	<score>	Under	</>
</style>

<style name="ACKNOWLEDGEMENTS">
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
	<text-before>Notices</>
</style>

<style name="BLOCKQUOTE">
	<left-indent>	&admonitions.left-indent	</>
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
</style>

<style name="BOOKBIBLIO">
	<space-after>	&float.space-after	</>
</style>

<!-- Front matter elements -->
<style name="BOOKINFO">
	<space-after>	&float.space-after	</>
</style>


<!-- Character formats. -->
<style name="CITETITLE">
	<font-slant>	Italic	</>
</style>

<style name="COLHEADS,HEAD1">
	<select>	if(attr(termlength,ancestor(deflist)),DLE.TERM.attr(termlength,ancestor(deflist)),DLE.TERM.WIDE)</>
</style>

<style name="COLHEADS,HEAD2">
	<select>	if(attr(termlength,ancestor(deflist)),DLE.LISTITEM.attr(termlength,ancestor(deflist)), DLE.LISTITEM.WIDE)</>
</style>

<style name="COLLECTIONS">
	<hide>	Children	</>
</style>

<style name="COMMAND">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
	<text-after>if(attr(sectionref),if(eq(attr(sectionref),blank),,\(gamut(attr(sectionref), '1 1B 1B-U 1M 1M-U 1X 1X-U 2 3 3C 3C-U 3F 3F-U 3G 3G-U 3I 3I-U 3K 3K-U 3L 3L-U 3M 3M-U 3N 3N-U 3O 3O-U 3R 3R-U 3S 3S-U 3X 3X-U 4 4P 4P-U 5 5X 5X-U 6 7 7D 7D-U 7X 7X-U 8 8E 8E-U','1 1B 1B 1M 1M 1X 1X 2 3 3C 3C 3F 3F 3G 3G 3I 3I 3K 3K 3L 3L 3M 3M 3N 3N 3O 3O 3R 3R 3S 3S 3X 3X 4 4P 4P 5 5X 5X 6 7 7D 7D 7X 7X 8 8E 8E', join('??'))\)),)</>
</style>

<style name="COMMENT">
	<hide>		Children	</>
</style>

<style name="COPYRIGHT">
</style>

<style name="DATE">
	<left-indent>	+=50	</>
	<break-after>	Line	</>
</style>

<style name="DEFLIST">
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
</style>

<style name="DEFLIST,COLHEADS">
	<select>DEFLISTENTRY</>
</style>

<style name="DEFLISTENTRY">
	<space-after>&float.space-after</>
</style>

<style name="DEFLISTENTRY,LISTITEM">
	<select>if(attr(termlength,ancestor(deflist)),DLE.LISTITEM.attr(termlength,ancestor(deflist)),DLE.LISTITEM.WIDE)</>
</style>

<style name="DEFLISTENTRY,TERM">
	<select>	if(attr(termlength,ancestor(deflist)),DLE.TERM.attr(termlength,ancestor(deflist)),DLE.TERM.WIDE)</>
</style>

<style name="DLE.LISTITEM.">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<left-indent>	+=190	</>
	<space-after>	&float.space-after	</>
</style>

<style name="DLE.LISTITEM.NARROW">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<left-indent>	+=90	</>
	<space-after>	&float.space-after	</>
</style>

<style name="DLE.LISTITEM.NEXTLINE">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<break-before>	if(ancestor(COLHEADS),None,Line)</>
	<left-indent>	+=75	</>
	<space-after>	&float.space-after	</>
</style>

<style name="DLE.LISTITEM.STANDARD">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<left-indent>	+=190	</>
	<space-after>	&float.space-after	</>
</style>

<style name="DLE.LISTITEM.WIDE">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<left-indent>	+=200	</>
	<space-after>	if(ancestor(COLHEADS),8,)	</>
</style>

<style name="DLE.TERM.">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<width>	175	</>
</style>

<style name="DLE.TERM.NARROW">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<width>	75	</>
</style>

<style name="DLE.TERM.NEXTLINE">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<width>	115	</>
</style>

<style name="DLE.TERM.STANDARD">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<width>	185	</>
</style>

<style name="DLE.TERM.WIDE">
	<font-weight>	if(ancestor(COLHEADS),Bold,)	</>
	<width>	195	</>
	<column>	True	</>
</style>

<style name="EMPHASIS">
	<font-weight>	Bold	</>
</style>

<style name="ENTRY">
	<left-indent>	mult(0.7,tableinfo(cals,left-indent, 10))</>
	<right-indent>	0					</>
	<width>	mult(0.7,tableinfo(cals, width, 10))		</>
	<justification>	tableinfo(cals,justification,16)	</>
	<column>	True	</>
</style>

<style name="ENTRY,PARA">
	<break-before>	if(isfirst(),none,true)	</>
</style>

<!-- Equation elements. -->
<style name="EQUATION">
	<foreground>	green	</>
	<left-indent>	&admonitions.left-indent	</>
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
	<hide>	Children	</>
	<inline>	equation target=me()	</>
	<text-before>[Equation gcnum()]</>
</style>

<style name="EXAMPLE">
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
</style>

<!-- Figures, examples and graphics. -->
<style name="FIGURE">
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
</style>

<style name="FILENAME">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
</style>

<style name="FIRSTTERM">
	<font-slant>	Italic	</>
</style>

<!-- Elements that link: footnote, link, xref. -->

<style name="FOOTNOTE">
	<font-size>	&smaller.font-size	</>
	<foreground>	&hot-text.foreground	</>
	<left-indent>	-=10			</>
	<vertical-offset>	&super.vertical-offset	</>
	<hide>	Children			</>
	<script> ebt-reveal window="New" stylesheet="fulltext.v" hscroll="False" width=450 title="Footnote gcnum(), content(typechild(ancestor(book),title))"	</>
	<text-before>gcnum()</>
</style>

<style name="FOOTNOTE,PARA">
	<font-size>	&body.font-size	</>
	<foreground>	&body.foreground	</>
	<left-indent>	0	</>
	<right-indent>	0	</>
	<vertical-offset>	0	</>
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
</style>

<style name="GLOSSENTRY">
</style>

<style name="GLOSSENTRY,GLOSSDEF">
	<break-before>	True	</>
	<space-after>	&float.space-after	</>
</style>

<style name="GLOSSENTRY,GLOSSTERM">
	<font-family>	&titles.font-family	</>
	<font-weight>	Bold	</>
	<break-before>	True	</>
	<space-before>	12	</>
</style>

<style name="GLOSSTERM">
	<foreground>	&hot-text.foreground	</>
	<score>	Under	</>
	<script>	ebt-link target=idmatch(id, attr(linkend))	</>
</style>

<style name="GRAPHIC">
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
	<inline>	raster filename="attr(entityref)"	</>
</style>

<!-- Index and glossary elements. -->
<style name="INDEXTERM">
	<hide>	Children	</>
</style>

<style name="INLINEEQUATION">
	<foreground>	red	</>
	<hide>	Children	</>
	<inline>	equation target=me()	</>
	<text-before>[InlineEquation gcnum()]</>
</style>

<style name="INTERFACE,INTERFACE">
	<select>if(contains(qtag(me()),INTERFACEDEFINITION),INTERFACE.NESTED.MENU,INTERFACE.NESTED.INLINE)</>
</style>

<style name="INTERFACE.NESTED.MENU">
	<left-indent>+=15</>
	<break-before>	Line	</>
	<text-before> -></>
	<space-before>	0	</>
</style>

<style name="INTERFACE.NESTED.INLINE">
	<text-before> -></>
</style>

<style name="INTERFACE">
	<select>if(contains(qtag(me()),INTERFACEDEFINITION),INTERFACE.UNNESTED.MENU,INTERFACE.UNNESTED.INLINE)</>
</style>

<style name="INTERFACE.UNNESTED.MENU">
	<break-before>	Line	</>
	<space-before>	0	</>
	<left-indent></>
</style>

<style name="INTERFACE.UNNESTED.INLINE">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
</style>

<style name="ITEMIZEDLIST,LISTITEM,#TEXT-BEFORE">
	<font-family>	Symbol	</>
</style>

<style name="KEYCAP">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
</style>

<style name="LEGALNOTICE">
        <space-before>  if(isfirst(), 8, 0)       </>
        <space-after>   &float-value            </>
        <hrule> if(not(islast()),After,None)    </>
</style>

<style name="LEGALNOTICE,PARA">
        <space-after>   8       </>
        <break-after>   false   </>
</style>

<style name="LINEANNOTATION">
	<font-family>	&body.font-family	</>
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
	<break-before>	True	</>
</style>

<style name="LINK">
	<foreground>	&hot-text.foreground	</>
	<score>	Under	</>
</style>

<style name="LISTITEM,PARA">
	<left-indent>	if(ancestor(deflistentry,me(),1),+=0,+=15)</>
	<space-after>	&float.space-after	</>
	<break-before>	if(lsibling(TITLE),true,false)	</>
</style>

<style name="LITERAL">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
</style>

<style name="LOF">
</style>

<style name="LOT">
</style>

<style name="MEMBER.INLINE">
	<text-after>if(islast(),,\,\ )</>
</style>

<style name="MODREQ">
</style>

<!-- MSGSET styles. -->
<style name="MSG">
        <font-family>   &command.font-family    </>
        <font-size>     &command.font-size      </>
        <space-after>	2			</>
</style>
        
<style name="MSGENTRY">
	<space-after>	12			</>
</style>

<style name="MSGEXPLAN">
        <space-after>   &float.space-after      </>
</style>

<style name="MSGTEXT">
</style>

<style name="MSGINFO">
        <space-after>	4			</>
</style>

<style name="MSGLEVEL">
        <text-after> </>
</style>
        
<style name="MSGNO">
        <text-after>-</>
</style>

<style name="MSGNUMBER">
        <text-after>_</>
</style>

<style name="MSGSUBNO">
</style>

<style name="MSGORIG">
        <font-family>   &command.font-family    </>
        <font-size>     &command.font-size      </>
</style>

<style name="MSGSET">  
        <space-after>   &float.space-after      </>
</style>

        
<style name="NEWFEATURES">
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
</style>

<style name="NEWLINE">
	<text-before>	&emsp;	</>
	<space-after>	1	</>
	<break-after>	Line	</>
</style>

<style name="OPTIONAL">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
	<text-before>[</>
	<text-after>]</>
</style>

<style name="PARA">
	<space-after>	&float.space-after	</>
	<break-after>	if(lsibling(NOTE),false,if(lsibling(TITLE),true,false))	</>
</style>

<style name="PUBTYPE">
	<text-after>-</>
</style>

<style name="REPLACEABLE">
	<font-slant>	Italic	</>
	<break-before>	None	</>
</style>

<style name="REVHISTORY">
	<text-before>Record of Revision</>
</style>

<style name="REVISION">
	<space-before>	6	</>
	<break-after>	Line	</>
</style>

<style name="REVREMARK">
	<left-indent>	+=50	</>
	<break-after>	Line	</>
</style>

<style name="ROW">
	<break-after>	true	</>
	<space-before>	&row.space-before	</>
	<hrule>		None	</>
	<vrule>		None	</>
</style>

<style name="SCREENINFO">
	<hide>	Children	</>
</style>

<style name="SCREENSHOT">
	<space-before>	&float.space-before	</>
	<space-after>	&float.space-after	</>
</style>

<style name="SIMPLELIST.INLINE">
</style>

<style name="STOCKNUM">
	<text-after> </>
</style>

<style name="STRUCTNAME">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
</style>

<style name="SUBSCRIPT">
	<font-size>	&smaller.font-size	</>
	<vertical-offset>	&sub.vertical-offset	</>
</style>

<style name="SUPERSCRIPT">
	<font-size>	&smaller.font-size	</>
	<vertical-offset>	&super.vertical-offset	</>
</style>

<style name="SYNOPSIS">
	<break-before>	Line	</>
	<break-after>	Line	</>
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
	<hrule>		if(ancestor(synopsis),None,Children)	</>
	<vrule>		None </>
	<justification>	if(eq(attr(format),yes),Verbatim,Left)	</>
	<space-before>	if(eq(attr(format),yes),8, &float.space-before,)</>
	<space-after>	if(eq(attr(format),yes),8, &float.space-after,)	</>
</style>

<!-- Table elements. -->
<style name="TABLE">
	<left-indent>	&body.left-indent	</>
	<right-indent>	0			</>
	<space-before>	10			</>
	<space-after>	10			</>
	<text-before>if(eq(typechild('title',me()),0),Table gcnum(me()).,)</>
	<hrule>		None			</>
	<vrule>		None			</>
</style>

<style name="TGROUP">
	<font-size>	&table.font-size	</>
	<hrule>		None			</>
	<vrule>		None			</>
</style>

<style name="THEAD">
	<font-weight>	Bold	</>
	<hrule>		Before	</>
	<vrule>		None	</>
</style>

<style name="TBODY">
	<hrule>if(lsibling(THEAD),After,Surround)</>
	<vrule>		None	</>
</style>

<style name="TOC">
</style>

<style name="USERINPUT">
	<font-family>	&command.font-family	</>
	<font-size>	&command.font-size	</>
	<font-weight>	Bold	</>
</style>

</sheet>
