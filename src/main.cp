
#include "flags/Base.h"
#include "Pcre2Base.h"
#include "Matcher.h"
#include "Replacer.h"

extern "C" {

PHPCPP_EXPORT void *get_module()
{
	// static, Php::Extension object that should stay in memory
	// for the entire duration of the process
	static Php::Extension extension("diskerror_pcre2", "0.2");

	////////////////////////////////////////////////////////////////////////////
	Php::Class<Pcre2Base> pcre2abstract("Diskerror\\Pcre2\\Pcre2Abstract", Php::Abstract);

	pcre2abstract.method<&Pcre2Base::__construct>("__construct", {
		Php::ByVal("regex", Php::Type::String, false),
		Php::ByVal("compileFlags", Php::Type::Numeric, false),
		Php::ByVal("matchFlags", Php::Type::Numeric, false)
	});

	pcre2abstract.method<&Pcre2Base::compile>("compile", {
		Php::ByVal("regex", Php::Type::String, false),
		Php::ByVal("compileFlags", Php::Type::Numeric, false),
		Php::ByVal("matchFlags", Php::Type::Numeric, false)
	});

	pcre2abstract.method<&Pcre2Base::setRegex>("setRegex", {
		Php::ByVal("regex", Php::Type::String, true),
		Php::ByVal("compileFlags", Php::Type::Numeric, false),
		Php::ByVal("matchFlags", Php::Type::Numeric, false)
	});

	pcre2abstract.method<&Pcre2Base::getRegex>("getRegex");

	pcre2abstract.property("compileFlags", &Pcre2Base::getCompileFlags);
	pcre2abstract.property("matchFlags", &Pcre2Base::getMatchFlags);


	////////////////////////////////////////////////////////////////////////////
	Php::Class<Matcher> matcher("Diskerror\\Pcre2\\Matcher");

	matcher.extends(pcre2abstract);

	matcher.method<&Matcher::hasMatch>("hasMatch", {
		Php::ByVal("subject", Php::Type::String, true),
		Php::ByVal("offset", Php::Type::Numeric, false)
	});

	matcher.method<&Matcher::match>("match", {
		Php::ByVal("subject", Php::Type::String, true),
		Php::ByVal("offset", Php::Type::Numeric, false)
	});

	matcher.method<&Matcher::matchAll>("matchAll", {
		Php::ByVal("subject", Php::Type::String, true),
		Php::ByVal("offset", Php::Type::Numeric, false)
	});


	////////////////////////////////////////////////////////////////////////////
	Php::Class<Replacer> replacer("Diskerror\\Pcre2\\Replacer");

	replacer.extends(pcre2abstract);

	replacer.method<&Replacer::__construct>("__construct", {
		Php::ByVal("regex", Php::Type::String, false),
		Php::ByVal("replacement", Php::Type::String, false),
		Php::ByVal("compileFlags", Php::Type::Numeric, false),
		Php::ByVal("matchFlags", Php::Type::Numeric, false)
	});

	replacer.method<&Replacer::replace>("replace", {
		Php::ByVal("subject", Php::Type::String, true),
		Php::ByVal("offset", Php::Type::Numeric, false)
	});

	replacer.method<&Replacer::setReplacement>("setReplacement", {
		Php::ByVal("regex", Php::Type::String, false),
		Php::ByVal("replaceFlags", Php::Type::Numeric, false)
	});

	replacer.method<&Replacer::getReplacement>("getReplacement");

	replacer.property("replaceFlags", &Pcre2Base::getMatchFlags);



	////////////////////////////////////////////////////////////////////////////
	Php::Class<Flags::Base> baseFlags("Diskerror\\Pcre2\\Flags\\FlagsAbstract", Php::Abstract);

	baseFlags.method<&Flags::Base::__construct>("__construct", {
		Php::ByVal("flags", Php::Type::Numeric, false)
	});

	baseFlags.method<&Flags::Base::add>("add", {
		Php::ByVal("flag", Php::Type::Numeric, true)
	});

	baseFlags.method<&Flags::Base::remove>("remove", {
		Php::ByVal("whichFlag", Php::Type::Numeric, true)
	});

	baseFlags.method<&Flags::Base::clear>("clear");

	baseFlags.method<&Flags::Base::set>("set", {
		Php::ByVal("flags", Php::Type::Numeric, true)
	});

	baseFlags.method<&Flags::Base::hasFlag>("hasFlag", {
		Php::ByVal("whichFlag", Php::Type::Numeric, false)
	});

	baseFlags.method<&Flags::Base::get>("get", {
		Php::ByVal("flags", Php::Type::Numeric, false)
	});

	baseFlags.method<&Flags::Base::getChanged>("getChanged");

	baseFlags.method<&Flags::Base::clearChanged>("clearChanged");

	baseFlags.property("ENDANCHORED", Flags::Base::ENDANCHORED, Php::Const);
	baseFlags.property("NO_UTF_CHECK", Flags::Base::NO_UTF_CHECK, Php::Const);
	baseFlags.property("ANCHORED", Flags::Base::ANCHORED, Php::Const);


	////////////////////////////////////////////////////////////////////////////
	Php::Class<Flags::Compile> compileFlags("Diskerror\\Pcre2\\Flags\\Compile");

	compileFlags.extends(baseFlags);

	compileFlags.property("ALLOW_EMPTY_CLASS", Flags::Compile::ALLOW_EMPTY_CLASS, Php::Const);
	compileFlags.property("ALT_BSUX", Flags::Compile::ALT_BSUX, Php::Const);
	compileFlags.property("AUTO_CALLOUT", Flags::Compile::AUTO_CALLOUT, Php::Const);
	compileFlags.property("CASELESS", Flags::Compile::CASELESS, Php::Const);
	compileFlags.property("DOLLAR_ENDONLY", Flags::Compile::DOLLAR_ENDONLY, Php::Const);
	compileFlags.property("DOTALL", Flags::Compile::DOTALL, Php::Const);
	compileFlags.property("DUPNAMES", Flags::Compile::DUPNAMES, Php::Const);
	compileFlags.property("EXTENDED", Flags::Compile::EXTENDED, Php::Const);
	compileFlags.property("FIRSTLINE", Flags::Compile::FIRSTLINE, Php::Const);
	compileFlags.property("MATCH_UNSET_BACKREF", Flags::Compile::MATCH_UNSET_BACKREF, Php::Const);
	compileFlags.property("MULTILINE", Flags::Compile::MULTILINE, Php::Const);
	compileFlags.property("NEVER_UCP", Flags::Compile::NEVER_UCP, Php::Const);
	compileFlags.property("NEVER_UTF", Flags::Compile::NEVER_UTF, Php::Const);
	compileFlags.property("NO_AUTO_CAPTURE", Flags::Compile::NO_AUTO_CAPTURE, Php::Const);
	compileFlags.property("NO_AUTO_POSSESS", Flags::Compile::NO_AUTO_POSSESS, Php::Const);
	compileFlags.property("NO_DOTSTAR_ANCHOR", Flags::Compile::NO_DOTSTAR_ANCHOR, Php::Const);
	compileFlags.property("NO_START_OPTIMIZE", Flags::Compile::NO_START_OPTIMIZE, Php::Const);
	compileFlags.property("UCP", Flags::Compile::UCP, Php::Const);
	compileFlags.property("UNGREEDY", Flags::Compile::UNGREEDY, Php::Const);
	compileFlags.property("UTF", Flags::Compile::UTF, Php::Const);
	compileFlags.property("NEVER_BACKSLASH_C", Flags::Compile::NEVER_BACKSLASH_C, Php::Const);
	compileFlags.property("ALT_CIRCUMFLEX", Flags::Compile::ALT_CIRCUMFLEX, Php::Const);
	compileFlags.property("ALT_VERBNAMES", Flags::Compile::ALT_VERBNAMES, Php::Const);
	compileFlags.property("USE_OFFSET_LIMIT", Flags::Compile::USE_OFFSET_LIMIT, Php::Const);
	compileFlags.property("EXTENDED_MORE", Flags::Compile::EXTENDED_MORE, Php::Const);
	compileFlags.property("LITERAL", Flags::Compile::LITERAL, Php::Const);
	compileFlags.property("DO_JIT", Flags::Compile::DO_JIT, Php::Const);


	////////////////////////////////////////////////////////////////////////////
	Php::Class<Flags::Match> matchFlags("Diskerror\\Pcre2\\Flags\\Match");

	matchFlags.extends(baseFlags);

	matchFlags.property("NOTBOL", Flags::Match::NOTBOL, Php::Const);
	matchFlags.property("NOTEOL", Flags::Match::NOTEOL, Php::Const);
	matchFlags.property("NOTEMPTY", Flags::Match::NOTEMPTY, Php::Const);
	matchFlags.property("NOTEMPTY_ATSTART", Flags::Match::NOTEMPTY_ATSTART, Php::Const);


	////////////////////////////////////////////////////////////////////////////
	Php::Class<Flags::Replace> replaceFlags("Diskerror\\Pcre2\\Flags\\Replace");

	replaceFlags.extends(matchFlags);

	replaceFlags.property("GLOBAL", Flags::Replace::GLOBAL, Php::Const);
	replaceFlags.property("EXTENDED", Flags::Replace::EXTENDED, Php::Const);
	replaceFlags.property("UNSET_EMPTY", Flags::Replace::UNSET_EMPTY, Php::Const);
	replaceFlags.property("UNKNOWN_UNSET", Flags::Replace::UNKNOWN_UNSET, Php::Const);


	////////////////////////////////////////////////////////////////////////////
	extension.add(std::move(pcre2abstract));
	extension.add(std::move(matcher));
	extension.add(std::move(replacer));
	extension.add(std::move(baseFlags));
	extension.add(std::move(compileFlags));
	extension.add(std::move(matchFlags));
	extension.add(std::move(replaceFlags));

	////////////////////////////////////////////////////////////////////////////
	// return the extension
	return extension.module();
}


}    //	extern "C"