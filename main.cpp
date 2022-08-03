#include "src/basiccontroller.h"

#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>

namespace {

const QString REGISTER_OBJECT =
    QStringLiteral("Object called '%1' has been registered in QML part of application");

}

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  QObject::connect(&engine, &QQmlApplicationEngine::exit, &app, &QApplication::exit,
                   Qt::QueuedConnection);
  QObject::connect(&engine, &QQmlApplicationEngine::quit, &app, &QApplication::quit,
                   Qt::QueuedConnection);

  BasicController* basicController = new BasicController(&app);

  for (const auto& [name, object] : basicController->getObjectsToRegister()) {
    engine.rootContext()->setContextProperty(name, object);
    qDebug() << REGISTER_OBJECT.arg(name);
  }

  engine.load(QUrl("qrc:/src/main.qml"));

  return app.exec();
}
