//todo: subsequent versions of Visual C++ provide access to these type of features
//#ifndef FUTURE_THEN_H
//#define FUTURE_THEN_H
//
//#include "future_then.h"
//
//#include <future>
//
//
//namespace std {
//
//    namespace detail {
//
//        template<typename T, typename Work>
//        auto then_work(std::future<T>& f, Work& w)-> decltype(w(f.get())) {
//            return w(f.get());
//        }
//
//        template<typename Work>
//        auto then_work(std::future<void>& f, Work& w)-> decltype(w()) {
//            f.wait();
//            return w();
//        }
//    }
//
//    ///http://stackoverflow.com/questions/14489935/implementing-futurethen-equivalent-for-asynchronous-execution-in-c11
//    ///http://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2012-Herb-Sutter-Concurrency-and-Parallelism
//    template<typename T, typename Work>
//    auto then(std::future<T>& f, Work& w) -> std::future<decltype(w(f.get()))> {
//        return std::async([](future<T>& f, Work& w)
//        { return detail::then_work(f, w); }, std::move(f), std::move(w));
//    }
//}
//
//#endif //FUTURE_THEN_H
